// ---------------------------------------------------------------------
//
// Copyright (C) 2010 - 2018 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


// check serialization for QIterated

#include <deal.II/base/quadrature.h>

#include <boost/serialization/vector.hpp>

#include "serialization.h"

void
test()
{
  const unsigned int dim      = 2;
  unsigned int       n_copies = 3;

  std::vector<Point<1>> points1;
  points1.push_back(Point<1>(0.));
  points1.push_back(Point<1>(1.));
  double              w1[2] = {0.5, 0.5};
  std::vector<double> weights1(w1, &w1[2]);

  std::vector<Point<1>> points2;
  points2.push_back(Point<1>(0.25));
  points2.push_back(Point<1>(0.75));
  double              w2[2] = {0.4, 0.6};
  std::vector<double> weights2(w2, &w2[2]);

  Quadrature<1> qx(points1, weights1);
  Quadrature<1> qy(points2, weights2);

  QIterated<dim> q1(qx, n_copies);

  QIterated<dim> q2(qy, n_copies);

  verify(q1, q2);
}


int
main()
{
  initlog();
  deallog << std::setprecision(3);

  test();

  deallog << "OK" << std::endl;
}
