/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:30:49 by jinam             #+#    #+#             */
/*   Updated: 2025/03/13 19:17:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"
int	main(void)
{
	Graph	g1(4,4);

	g1.addNewVector(0, 0);
	g1.addNewVector(2,2);
	g1.addNewVector(4, 2);
	g1.addNewVector(2, 4);
	g1.addNewVector(9, 1);
	g1.renderGraph();
	
	return (0);
}
