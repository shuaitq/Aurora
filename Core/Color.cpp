#include "Color.hpp"

namespace Aurora
{
	template <>
	const RGB_T<float> RGB_T<float>::black(0, 0, 0);
	template <>
	const RGB_T<float> RGB_T<float>::white(1, 1, 1);	

	template <>
	const RGBA_T<float> RGBA_T<float>::black(0, 0, 0, 1);
	template <>
	const RGBA_T<float> RGBA_T<float>::white(1, 1, 1, 1);
}
