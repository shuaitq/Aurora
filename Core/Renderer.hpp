#ifndef AURORA_RENDERER_HPP_
#define AURORA_RENDERER_HPP_

#include "Camera.hpp"
#include "Color.hpp"
#include "../Utility/SenceFile.hpp"

#include <memory>
#include <vector>
#include <string>

namespace Aurora
{
	class Renderer
	{
	public:
		void Load(const std::string &path)
		{
			SenceFile::Load(path, width_, height_, camera_, object_);
		}
		void Render()
		{
			screen_.resize(width_ * height_);
			ZBuffer_.resize(width_ * height_);
			std::vector<Object> CopyObject = object_;
			std::vector<Vertex> &vertex = CopyObject.verex();
			std::vector<Triangle> &tri = CopyObject[0].triangle();
			Matrix4_T<float> m;
			bool flag[CopyObject[0].triangle().size()];
			for(auto it = vertex.begin(); it!= vertex.end(); ++ it)
			{
				
			}
			PPM::Save("image/cude.ppm", width_, height_, screen_);
		}

		Camera& camera()
		{
			return camera_;
		}
		const Camera& camera() const
		{
			return camera_;
		}
		std::vector<Object>& object()
		{
			return object_;
		}
		const std::vector<Object>& object() const
		{
			return object_;
		}
		size_t& width()
		{
			return width_;
		}
		const size_t& width() const
		{
			return width_;
		}
		size_t& height()
		{
			return height_;
		}
		const size_t& height() const
		{
			return height_;
		}
		
		friend std::ostream& operator << (std::ostream &out, const Renderer &r)
		{
			out << "# Renderer" << std::endl;
			out << r.camera();
			for(auto it = r.object().begin(); it != r.object().end(); ++ it)
			{
				out << *it;
			}
			out << "# width height" << std::endl;
			out << r.width() << ' ' << r.height() << std::endl;
			return out;
		}
	private:
		Camera camera_;
		std::vector<RGB_T<float>> screen_;
		std::vector<Object> object_;
		std::vector<float> ZBuffer_;
		size_t width_;
		size_t height_;
	};
}

#endif //AURORA_RENDERER_HPP_
