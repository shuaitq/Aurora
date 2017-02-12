#ifndef AURORA_VERTEX_HPP_
#define AURORA_VERTEX_HPP_

#include "../Math/Math.hpp"

namespace Aurora
{
	class Vertex
	{
	public:
		Vertex():point_(0), uv_(0), normal_(0){}
		Vertex(const Point4D_T<float> &point, const Point2D_T<float> &uv, const Vector4D_T<float> &normal):point_(point), uv_(uv), normal_(normal){}
		Vertex(const Vertex &ver):point_(ver.point_), uv_(ver.uv_), normal_(ver.normal_){}
		Vertex& operator=(const Vertex &ver)
		{
			point_ = ver.point_;
			uv_ = ver.uv_;
			normal_ = ver.normal_;
			return *this;
		}
	private:
		Point4D_T<float> point_;
		Point2D_T<float> uv_;
		Vector4D_T<float> normal_;
	};
}

#endif //AURORA_VERTEX_HPP_
