/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:50:56 by jinam             #+#    #+#             */
/*   Updated: 2025/03/13 18:59:55 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

#include "Vector2.hpp"
#include <vector>
class Graph 
{
private:
	Vector2							size;
	std::vector<Vector2> 			vectors;
	std::vector<std::vector<char> >	graph;
	static const char				POINT;
	static const char				EMPTY;

private:
	void	initGraph(void);
	void	markGraph(void);
	typedef std::vector<Vector2>::iterator vecIter;

public:
	Graph(float h, float w);
	Graph();
	~Graph();
	void	addNewVector(float x, float y);
	void	renderGraph(void);
};
#endif
