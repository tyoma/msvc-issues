#include <cstdint>
#include <iostream>
#include <type_traits>

using namespace std;

template <typename T, unsigned bits = sizeof(T) * 8>
inline constexpr typename std::enable_if<std::is_unsigned<T>::value && sizeof(T) <= 8, unsigned>::type CountLeadingZeros(T value)
{
	static_assert(bits > 0, "invalid instantiation");
	// Binary search algorithm taken from "Hacker's Delight" (by Henry S. Warren, Jr.), figures 5-11 and 5-12.
	if (bits == 1) return static_cast<unsigned>(value) ^ 1;
	T upper_half = value >> (bits / 2);
	T next_value = upper_half != 0 ? upper_half : value;
	unsigned add = upper_half != 0 ? 0 : bits / 2;
	constexpr unsigned next_bits = bits == 1 ? 1 : bits / 2;
	return CountLeadingZeros<T, next_bits>(next_value) + add;
}

__declspec(noinline) uint32_t RoundUpToPowerOfTwo32(uint32_t value)
{
	return 1u << (32 - CountLeadingZeros(value));
}

int main()
{
	for (int i = 0; i < 1000; ++i)
		cout << RoundUpToPowerOfTwo32(i) << endl;
	return 0;
}
