#ifndef AURORA_POINT_H_
#define AURORA_POINT_H_

namespace aurora
{
	template <typename T>
	class Point2D
	{
	public:
		Point2D():x(0),y(0){}
		Point2D(const T x,const T y):x(x_),{}
		T x,y;
	}
}

#endif //AURORA_POINT_H_
