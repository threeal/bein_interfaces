// Copyright (c) 2021 Alfi Maulana
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef BEINE_CPP__UTILITY_HPP_
#define BEINE_CPP__UTILITY_HPP_

#include <std_msgs/msg/string.hpp>
#include <beine_interfaces/beine_interfaces.hpp>

#include "./utility/stance.hpp"

namespace beine_cpp
{

using Joints = beine_interfaces::msg::Joints;
using Orientation = beine_interfaces::msg::Orientation;
using Position = beine_interfaces::msg::Position;
using StringMsg = std_msgs::msg::String;

}  // namespace beine_cpp

inline std::ostream & operator<<(std::ostream & out, const beine_cpp::Orientation & orientation)
{
  return out << orientation.x << ", " << orientation.y << ", " << orientation.z;
}

inline std::ostream & operator<<(std::ostream & out, const beine_cpp::Position & position)
{
  return out << position.x << ", " << position.y << ", " << position.z;
}

#endif  // BEINE_CPP__UTILITY_HPP_
