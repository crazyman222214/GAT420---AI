#pragma once
#include <vector>

template<typename T>
class Cells
{
public:

	Cells(int width, int height) : m_height{ height }, m_width{ width }
	{
		m_data.resize(width * height);
	}

	T Read(int x, int y) const { return m_data[x + (y * m_width)]; }
	void Write(int x, int y, const T& data) { m_data[x + (y * m_width)] = data; }


	int m_height{ 0 };
	int m_width{ 0 };

	std::vector<T> m_data;
};