/*  This file is part of the Vc library.

    Copyright (C) 2009-2012 Matthias Kretz <kretz@kde.org>

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

*/

#ifndef AVX_TYPES_H
#define AVX_TYPES_H

#include "../traits/type_traits.h"
#include "macros.h"

#ifdef VC_DEFAULT_IMPL_AVX2
#define VC_DOUBLE_V_SIZE 4
#define VC_FLOAT_V_SIZE 8
#define VC_INT_V_SIZE 8
#define VC_UINT_V_SIZE 8
// TODO: 16
#define VC_SHORT_V_SIZE 8
#define VC_USHORT_V_SIZE 8
#elif defined VC_DEFAULT_IMPL_AVX
#define VC_DOUBLE_V_SIZE 4
#define VC_FLOAT_V_SIZE 8
// TODO: 4
#define VC_INT_V_SIZE 8
#define VC_UINT_V_SIZE 8
#define VC_SHORT_V_SIZE 8
#define VC_USHORT_V_SIZE 8
#endif

namespace Vc_VERSIONED_NAMESPACE
{
namespace AVX
{
constexpr std::size_t VectorAlignment = 32;

template <typename T> class Vector;
typedef Vector<double>         double_v;
typedef Vector<float>           float_v;
typedef Vector<int>               int_v;
typedef Vector<unsigned int>     uint_v;
typedef Vector<short>           short_v;
typedef Vector<unsigned short> ushort_v;

template <typename T> class Mask;
typedef Mask<double>         double_m;
typedef Mask<float>           float_m;
typedef Mask<int>               int_m;
typedef Mask<unsigned int>     uint_m;
typedef Mask<short>           short_m;
typedef Mask<unsigned short> ushort_m;

template <typename V = Vector<float>> class alignas(alignof(V)) VectorAlignedBaseT;

template <typename T> struct is_vector : public std::false_type {};
template <typename T> struct is_vector<Vector<T>> : public std::true_type {};
template <typename T> struct is_mask : public std::false_type {};
template <typename T> struct is_mask<Mask<T>> : public std::true_type {};
}
namespace AVX2
{
constexpr std::size_t VectorAlignment = 32;

template<typename T> class Vector;
typedef Vector<double>         double_v;
typedef Vector<float>           float_v;
typedef Vector<int>               int_v;
typedef Vector<unsigned int>     uint_v;
typedef Vector<short>           short_v;
typedef Vector<unsigned short> ushort_v;

template<typename T> class Mask;
typedef Mask<double>         double_m;
typedef Mask<float>           float_m;
typedef Mask<int>               int_m;
typedef Mask<unsigned int>     uint_m;
typedef Mask<short>           short_m;
typedef Mask<unsigned short> ushort_m;

template <typename V = Vector<float>> class alignas(alignof(V)) VectorAlignedBaseT;

template <typename T> struct is_vector : public std::false_type {};
template <typename T> struct is_vector<Vector<T>> : public std::true_type {};
template <typename T> struct is_mask : public std::false_type {};
template <typename T> struct is_mask<Mask<T>> : public std::true_type {};
}

namespace Traits
{
template<typename T> struct is_simd_mask_internal<AVX::Mask<T>> : public std::true_type {};
template<typename T> struct is_simd_mask_internal<AVX2::Mask<T>> : public std::true_type {};
template<typename T> struct is_simd_vector_internal<AVX::Vector<T>> : public std::true_type {};
template<typename T> struct is_simd_vector_internal<AVX2::Vector<T>> : public std::true_type {};
}
}

#include "undomacros.h"

#endif // AVX_TYPES_H
