/*  This file is part of the Vc library. {{{

    Copyright (C) 2012 Matthias Kretz <kretz@kde.org>

    Vc is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    Vc is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Vc.  If not, see <http://www.gnu.org/licenses/>.

}}}*/

#ifndef VC_COMMON_CONST_H
#define VC_COMMON_CONST_H

namespace Vc
{
    template<typename T> struct Math;
    template<> struct Math<float>
    {
        static float e()         { return 2.7182818284590452353602874713526625f; }
        static float log2e()     { return 1.4426950408889634073599246810018921f; }
        static float log10e()    { return 0.4342944819032518276511289189166051f; }
        static float ln2()       { return 0.6931471805599453094172321214581766f; }
        static float ln10()      { return 2.3025850929940456840179914546843642f; }
        static float pi()        { return 3.1415926535897932384626433832795029f; }
        static float pi_2()      { return 1.5707963267948966192313216916397514f; }
        static float pi_4()      { return 0.7853981633974483096156608458198757f; }
        static float _1_pi()     { return 0.3183098861837906715377675267450287f; }
        static float _2_pi()     { return 0.6366197723675813430755350534900574f; }
        static float _2_sqrtpi() { return 1.1283791670955125738961589031215452f; }
        static float sqrt2()     { return 1.4142135623730950488016887242096981f; }
        static float sqrt1_2()   { return 0.7071067811865475244008443621048490f; }
    };
    template<> struct Math<double>
    {
        static double e()         { return 2.7182818284590452353602874713526625; }
        static double log2e()     { return 1.4426950408889634073599246810018921; }
        static double log10e()    { return 0.4342944819032518276511289189166051; }
        static double ln2()       { return 0.6931471805599453094172321214581766; }
        static double ln10()      { return 2.3025850929940456840179914546843642; }
        static double pi()        { return 3.1415926535897932384626433832795029; }
        static double pi_2()      { return 1.5707963267948966192313216916397514; }
        static double pi_4()      { return 0.7853981633974483096156608458198757; }
        static double _1_pi()     { return 0.3183098861837906715377675267450287; }
        static double _2_pi()     { return 0.6366197723675813430755350534900574; }
        static double _2_sqrtpi() { return 1.1283791670955125738961589031215452; }
        static double sqrt2()     { return 1.4142135623730950488016887242096981; }
        static double sqrt1_2()   { return 0.7071067811865475244008443621048490; }
    };
} // namespace Vc

#endif // VC_COMMON_CONST_H