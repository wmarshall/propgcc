// 2007-02-04  Edward Smith-Rowland <3dw4rd@verizon.net>
//
// Copyright (C) 2007, 2009 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

//  sph_bessel


//  Compare against values generated by the GNU Scientific Library.
//  The GSL can be found on the web: http://www.gnu.org/software/gsl/

#include <tr1/cmath>
#if defined(__TEST_DEBUG)
#include <iostream>
#define VERIFY(A) \
if (!(A)) \
  { \
    std::cout << "line " << __LINE__ \
      << "  max_abs_frac = " << max_abs_frac \
      << std::endl; \
  }
#else
#include <testsuite_hooks.h>
#endif
#include "../testcase.h"


// Test data for n=0.
testcase_sph_bessel<double> data001[] = {
  { 1.0000000000000000, 0, 0.0000000000000000 },
  { -0.19178485493262770, 0, 5.0000000000000000 },
  { -0.054402111088936986, 0, 10.000000000000000 },
  { 0.043352522677141132, 0, 15.000000000000000 },
  { 0.045647262536381385, 0, 20.000000000000000 },
  { -0.0052940700039109216, 0, 25.000000000000000 },
  { -0.032934387469762058, 0, 30.000000000000000 },
  { -0.012233790557032886, 0, 35.000000000000000 },
  { 0.018627829011983722, 0, 40.000000000000000 },
  { 0.018908967211869299, 0, 45.000000000000000 },
  { -0.0052474970740785751, 0, 50.000000000000000 },
  { -0.018177366788338544, 0, 55.000000000000000 },
  { -0.0050801770183702783, 0, 60.000000000000000 },
  { 0.012720441222924669, 0, 65.000000000000000 },
  { 0.011055581165112701, 0, 70.000000000000000 },
  { -0.0051704218054590724, 0, 75.000000000000000 },
  { -0.012423608174042190, 0, 80.000000000000000 },
  { -0.0020714778817480834, 0, 85.000000000000000 },
  { 0.0099332962622284207, 0, 90.000000000000000 },
  { 0.0071922285761696946, 0, 95.000000000000000 },
  { -0.0050636564110975880, 0, 100.00000000000000 },
};

// Test function for n=0.
template <typename Tp>
void test001()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data001)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data001[i].n), Tp(data001[i].x));
      const Tp f0 = data001[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000014e-11));
}

// Test data for n=1.
testcase_sph_bessel<double> data002[] = {
  { 0.0000000000000000, 1, 0.0000000000000000 },
  { -0.095089408079170795, 1, 5.0000000000000000 },
  { 0.078466941798751549, 1, 10.000000000000000 },
  { 0.053536029035730834, 1, 15.000000000000000 },
  { -0.018121739963850528, 1, 20.000000000000000 },
  { -0.039859875274695380, 1, 25.000000000000000 },
  { -0.0062395279119115375, 1, 30.000000000000000 },
  { 0.025470240415270681, 1, 35.000000000000000 },
  { 0.017139147266606137, 1, 40.000000000000000 },
  { -0.011253622702352454, 1, 45.000000000000000 },
  { -0.019404270511323839, 1, 50.000000000000000 },
  { -0.00073280223727807778, 1, 55.000000000000000 },
  { 0.015788880056613101, 1, 60.000000000000000 },
  { 0.0088488352686322581, 1, 65.000000000000000 },
  { -0.0088894803131598157, 1, 70.000000000000000 },
  { -0.012358955887069445, 1, 75.000000000000000 },
  { 0.0012245454458125673, 1, 80.000000000000000 },
  { 0.011556531358968161, 1, 85.000000000000000 },
  { 0.0050889656932377614, 1, 90.000000000000000 },
  { -0.0076103298149331573, 1, 95.000000000000000 },
  { -0.0086738252869878150, 1, 100.00000000000000 },
};

// Test function for n=1.
template <typename Tp>
void test002()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data002)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data002[i].n), Tp(data002[i].x));
      const Tp f0 = data002[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(5.0000000000000028e-11));
}

// Test data for n=2.
testcase_sph_bessel<double> data003[] = {
  { 0.0000000000000000, 2, 0.0000000000000000 },
  { 0.13473121008512520, 2, 5.0000000000000000 },
  { 0.077942193628562445, 2, 10.000000000000000 },
  { -0.032645316869994966, 2, 15.000000000000000 },
  { -0.048365523530958965, 2, 20.000000000000000 },
  { 0.00051088497094747614, 2, 25.000000000000000 },
  { 0.032310434678570907, 2, 30.000000000000000 },
  { 0.014416954021198945, 2, 35.000000000000000 },
  { -0.017342392966988262, 2, 40.000000000000000 },
  { -0.019659208725359461, 2, 45.000000000000000 },
  { 0.0040832408433991458, 2, 50.000000000000000 },
  { 0.018137395757214285, 2, 55.000000000000000 },
  { 0.0058696210212009327, 2, 60.000000000000000 },
  { -0.012312033441295490, 2, 65.000000000000000 },
  { -0.011436558892819550, 2, 70.000000000000000 },
  { 0.0046760635699762939, 2, 75.000000000000000 },
  { 0.012469528628260161, 2, 80.000000000000000 },
  { 0.0024793554591234306, 2, 85.000000000000000 },
  { -0.0097636640724538277, 2, 90.000000000000000 },
  { -0.0074325547808517939, 2, 95.000000000000000 },
  { 0.0048034416524879537, 2, 100.00000000000000 },
};

// Test function for n=2.
template <typename Tp>
void test003()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data003)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data003[i].n), Tp(data003[i].x));
      const Tp f0 = data003[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000014e-11));
}

// Test data for n=5.
testcase_sph_bessel<double> data004[] = {
  { 0.0000000000000000, 5, 0.0000000000000000 },
  { 0.10681116145650454, 5, 5.0000000000000000 },
  { -0.055534511621452197, 5, 10.000000000000000 },
  { 0.065968007076521964, 5, 15.000000000000000 },
  { 0.016683908063095686, 5, 20.000000000000000 },
  { -0.036117795989722368, 5, 25.000000000000000 },
  { -0.020504008736827509, 5, 30.000000000000000 },
  { 0.018499481206814564, 5, 35.000000000000000 },
  { 0.022448773791045016, 5, 40.000000000000000 },
  { -0.0048552694845020103, 5, 45.000000000000000 },
  { -0.020048300563664877, 5, 50.000000000000000 },
  { -0.0052999924455565672, 5, 55.000000000000000 },
  { 0.014151556281331405, 5, 60.000000000000000 },
  { 0.011354588594416765, 5, 65.000000000000000 },
  { -0.0064983781785323642, 5, 70.000000000000000 },
  { -0.013089909320064264, 5, 75.000000000000000 },
  { -0.00096200450071301611, 5, 80.000000000000000 },
  { 0.011048668899130202, 5, 85.000000000000000 },
  { 0.0065639581708135976, 5, 90.000000000000000 },
  { -0.0064646119368202771, 5, 95.000000000000000 },
  { -0.0092901489349075713, 5, 100.00000000000000 },
};

// Test function for n=5.
template <typename Tp>
void test004()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data004)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data004[i].n), Tp(data004[i].x));
      const Tp f0 = data004[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(5.0000000000000028e-11));
}

// Test data for n=10.
testcase_sph_bessel<double> data005[] = {
  { 0.0000000000000000, 10, 0.0000000000000000 },
  { 0.00040734424424946052, 10, 5.0000000000000000 },
  { 0.064605154492564279, 10, 10.000000000000000 },
  { 0.0018969790010883629, 10, 15.000000000000000 },
  { 0.039686698644626366, 10, 20.000000000000000 },
  { -0.036253285601128567, 10, 25.000000000000000 },
  { -0.014529646403897820, 10, 30.000000000000000 },
  { 0.026281264603993850, 10, 35.000000000000000 },
  { 0.013124803182748307, 10, 40.000000000000000 },
  { -0.017600831383728963, 10, 45.000000000000000 },
  { -0.015039221463465962, 10, 50.000000000000000 },
  { 0.0095256289349167356, 10, 55.000000000000000 },
  { 0.015822719394008342, 10, 60.000000000000000 },
  { -0.0019391391708249812, 10, 65.000000000000000 },
  { -0.014293389028395010, 10, 70.000000000000000 },
  { -0.0044210285031696184, 10, 75.000000000000000 },
  { 0.010516146958338822, 10, 80.000000000000000 },
  { 0.0086736275131325761, 10, 85.000000000000000 },
  { -0.0052905066357239365, 10, 90.000000000000000 },
  { -0.010258326955210765, 10, 95.000000000000000 },
  { -0.00019565785971342893, 10, 100.00000000000000 },
};

// Test function for n=10.
template <typename Tp>
void test005()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data005)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data005[i].n), Tp(data005[i].x));
      const Tp f0 = data005[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000017e-10));
}

// Test data for n=20.
testcase_sph_bessel<double> data006[] = {
  { 0.0000000000000000, 20, 0.0000000000000000 },
  { 5.4277267607932098e-12, 20, 5.0000000000000000 },
  { 2.3083719613194699e-06, 20, 10.000000000000000 },
  { 0.0015467058510412503, 20, 15.000000000000000 },
  { 0.038324851639805181, 20, 20.000000000000000 },
  { 0.028500071484154683, 20, 25.000000000000000 },
  { -0.014711593353429090, 20, 30.000000000000000 },
  { -0.010797653070264238, 20, 35.000000000000000 },
  { 0.026535391837540286, 20, 40.000000000000000 },
  { -0.011582959134716381, 20, 45.000000000000000 },
  { -0.015785029898269291, 20, 50.000000000000000 },
  { 0.013885519185862756, 20, 55.000000000000000 },
  { 0.011112458964023256, 20, 60.000000000000000 },
  { -0.011938384963927570, 20, 65.000000000000000 },
  { -0.010117695207156906, 20, 70.000000000000000 },
  { 0.0089871214102383128, 20, 75.000000000000000 },
  { 0.010400578884991936, 20, 80.000000000000000 },
  { -0.0055359020656326630, 20, 85.000000000000000 },
  { -0.010639343320787519, 20, 90.000000000000000 },
  { 0.0018051661455979488, 20, 95.000000000000000 },
  { 0.010107671283873054, 20, 100.00000000000000 },
};

// Test function for n=20.
template <typename Tp>
void test006()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data006)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data006[i].n), Tp(data006[i].x));
      const Tp f0 = data006[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000014e-11));
}

// Test data for n=50.
testcase_sph_bessel<double> data007[] = {
  { 0.0000000000000000, 50, 0.0000000000000000 },
  { 2.8574793504401511e-46, 50, 5.0000000000000000 },
  { 2.2306960232186471e-31, 50, 10.000000000000000 },
  { 7.6804716640080780e-23, 50, 15.000000000000000 },
  { 5.6500807918725294e-17, 50, 20.000000000000000 },
  { 1.2540416973758975e-12, 50, 25.000000000000000 },
  { 2.6901637185735330e-09, 50, 30.000000000000000 },
  { 1.0167148174422245e-06, 50, 35.000000000000000 },
  { 9.3949174038179191e-05, 50, 40.000000000000000 },
  { 0.0024888927213794552, 50, 45.000000000000000 },
  { 0.018829107369282640, 50, 50.000000000000000 },
  { 0.026373198438145548, 50, 55.000000000000000 },
  { -0.021230978268739008, 50, 60.000000000000000 },
  { 0.016539881802291316, 50, 65.000000000000000 },
  { -0.015985416061436657, 50, 70.000000000000000 },
  { 0.015462548984405593, 50, 75.000000000000000 },
  { -0.010638570118081834, 50, 80.000000000000000 },
  { 0.00046961239784540576, 50, 85.000000000000000 },
  { 0.0096065882189920234, 50, 90.000000000000000 },
  { -0.010613873910261147, 50, 95.000000000000000 },
  { 0.00057971408822773810, 50, 100.00000000000000 },
};

// Test function for n=50.
template <typename Tp>
void test007()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data007)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data007[i].n), Tp(data007[i].x));
      const Tp f0 = data007[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000017e-10));
}

// Test data for n=100.
testcase_sph_bessel<double> data008[] = {
  { 0.0000000000000000, 100, 0.0000000000000000 },
  { 5.5356503033889938e-120, 100, 5.0000000000000000 },
  { 5.8320401820058771e-90, 100, 10.000000000000000 },
  { 1.7406387750766626e-72, 100, 15.000000000000000 },
  { 3.5152711125317001e-60, 100, 20.000000000000000 },
  { 9.8455459353816024e-51, 100, 25.000000000000000 },
  { 4.0888596744301567e-43, 100, 30.000000000000000 },
  { 8.8975854911134006e-37, 100, 35.000000000000000 },
  { 2.1513492547733837e-31, 100, 40.000000000000000 },
  { 9.3673586994539323e-27, 100, 45.000000000000000 },
  { 1.0190122629310465e-22, 100, 50.000000000000000 },
  { 3.4887804977690321e-19, 100, 55.000000000000000 },
  { 4.4442883425555691e-16, 100, 60.000000000000000 },
  { 2.3832619568710733e-13, 100, 65.000000000000000 },
  { 5.8948384175608103e-11, 100, 70.000000000000000 },
  { 7.1884446357022268e-09, 100, 75.000000000000000 },
  { 4.5247964400094991e-07, 100, 80.000000000000000 },
  { 1.5096093228779059e-05, 100, 85.000000000000000 },
  { 0.00026825172647807507, 100, 90.000000000000000 },
  { 0.0024744308520581030, 100, 95.000000000000000 },
  { 0.010880477011438327, 100, 100.00000000000000 },
};

// Test function for n=100.
template <typename Tp>
void test008()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data008)
                         / sizeof(testcase_sph_bessel<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::sph_bessel(Tp(data008[i].n), Tp(data008[i].x));
      const Tp f0 = data008[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(5.0000000000000029e-12));
}

int main(int, char**)
{
  test001<double>();
  test002<double>();
  test003<double>();
  test004<double>();
  test005<double>();
  test006<double>();
  test007<double>();
  test008<double>();
  return 0;
}
