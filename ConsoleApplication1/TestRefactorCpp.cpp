#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>

class InputData {
	char szDATA[32];
public:
	InputData() noexcept
	{
		*szDATA = '\0';
	}
	constexpr bool operator!() const noexcept
	{
		return *szDATA == '\0'|| strcmp(szDATA, "E") == 0 || strcmp(szDATA, "e") == 0;
	}
	constexpr operator bool() const noexcept
	{
		return !!*this;
	}
	InputData& Input()
	{
		if (!gets_s(szDATA, sizeof szDATA)) {
			//入力失敗
			*szDATA = '\0';
		}
		return *this;
	}
	double value() const noexcept
	{
		return atof(szDATA);
	}
};
class Memory {
	double* pd;
	size_t no;
public:
	constexpr Memory(double*&&pd, size_t &&no) noexcept
		: pd{pd}
		, no{no}
	{
		pd = nullptr;
		no = 0;
	}
	constexpr Memory() noexcept
		: Memory
			{ nullptr
			, 0
			}
	{
	}
	Memory(Memory&& r) noexcept
		: Memory
			{ std::move(r.pd)
			, std::move(r.no)
			}
	{
	}
	Memory& operator=(Memory&& r) noexcept
	{
		std::swap(pd, r.pd);
		std::swap(no, r.no);
		return *this;
	}
	~Memory()
	{
		free(pd);
	}
	constexpr operator bool() const noexcept
	{
		return no;
	}
	constexpr size_t size() const noexcept
	{
		return no;
	}
	bool AddData(double value)
	{
		if (const auto pd2 = static_cast<double*>(realloc(pd, (no + 1) * sizeof * pd))) {
			(pd = pd2)[no] = value;
			++no;
			return true;
		}
		else {
			if (no == 0)
				perror("領域確保に失敗\n");
			else
				perror("領域のサイズ変更に失敗しました\n");
			return false;
		}
	}
	constexpr const double* begin() const noexcept
	{
		return pd;
	}
	constexpr const double* end() const noexcept
	{
		return &pd[no];
	}
	double sum() const noexcept
	{
		double sum = 0;
		for (size_t i = 0; i < no; ++i)
			sum += pd[i];
		return sum;
	}
};

Memory Input()
{
	Memory m;
	for (;;) {
		printf("数値を入力してください。(Eで終了)");
		InputData d;
		//入力成功
		if (d.Input()) {
			if (m.AddData(d.value()))
				continue;
			else
				break;
		}
		else {
			printf("入力を終了します\n");
			break;
		}
	}
	return m;
}

int main() {
	if (Memory m = Input()) {
		for (const auto& r : m)
			printf("[No.%d]%f\n", static_cast<int>(& r - m.begin()), r);
		const auto sum = m.sum();
		printf("合計\t%f\n", sum);
		printf("平均\t%f\n", sum / m.size());
	}
	return 0;
}
