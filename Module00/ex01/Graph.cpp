/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:18:17 by jinam             #+#    #+#             */
/*   Updated: 2025/03/13 19:15:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"
#include <iostream>

const char Graph::POINT = 'X';
const char Graph::EMPTY = '.';

Graph::Graph()
	: size(0, 0)
{
}

void	Graph::initGraph(void)
{
	float	height = size.getY() + 2;
	float	width = size.getX() + 2;
	
	std::cout << height << " " <<  width << "!\n";
	//graph.resize(height, std::vector<char>(width, EMPTY));
	graph.resize(height);
	for (size_t i = 0; i < height; ++i)
	{
		std::cout << " Size change by : " << width << std::endl;
		graph[i].resize(width, EMPTY);
		std::cout << "Capacity: " << graph[i].capacity() << std::endl;

	}
}

Graph::Graph(float h, float w)
	:size(w, h)
{
	initGraph();
}

Graph::~Graph()
{}

void	Graph::addNewVector(float x, float y)
{
	if (x > size.getX() || y > size.getY())
	{
		size.resize(x, y);
		initGraph();
	}
	vectors.push_back(Vector2(x, y));
}

void	Graph::markGraph(void)
{
	vecIter	it;

	for (it = vectors.begin(); it != vectors.end(); it ++)
	{
		float x = it->getX();
		float y = it->getY();

		if (x < graph.size() && y < graph[x].size())
			graph[it->getY()][it->getX()] = POINT;
		else
		{
			graph[it->getY()][it->getX()] = POINT;
			std::cerr << "WARNING : vector position out of bounds ("
						<< x << ", " << y << ")\n";
		}
	}
}

void	Graph::renderGraph(void)
{
	float	height = size.getY() + 2;
	float	width = size.getX() + 2;

	markGraph();
	for (int i = height - 1; i >= 0; i--)
	{
		std::cout << i << ' ';
		for (int j = 0; j <= width; j++)
		{
	   		std::cout << graph[i][j];
			if (j != width - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width; i ++)
	{
		if (i == 0)
			std::cout << "  " << i << ' ';
		else if (i == width)
			std::cout << i;
		else
			std::cout << i << ' ';
	}
}
