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

#ifndef BEINE_CPP__CONSUMER__LEGS_CONSUMER_HPP_
#define BEINE_CPP__CONSUMER__LEGS_CONSUMER_HPP_

#include <rclcpp/rclcpp.hpp>

#include <string>

#include "../utility.hpp"

namespace beine_cpp
{

class LegsConsumer
{
public:
  inline LegsConsumer();
  inline explicit LegsConsumer(rclcpp::Node::SharedPtr node);

  inline void set_node(rclcpp::Node::SharedPtr node);

  inline rclcpp::Node::SharedPtr get_node() const;

  inline const Position & get_position() const;
  inline const Orientation & get_orientation() const;
  inline const Stance & get_stance() const;
  inline const std::string & get_command() const;

private:
  rclcpp::Node::SharedPtr node;

  rclcpp::Subscription<Position>::SharedPtr position_subscription;
  rclcpp::Subscription<Orientation>::SharedPtr orientation_subscription;
  rclcpp::Subscription<StanceMsg>::SharedPtr stance_subscription;
  rclcpp::Subscription<StringMsg>::SharedPtr command_subscription;

  Position current_position;
  Orientation current_orientation;
  Stance current_stance;
  std::string current_command;
};

LegsConsumer::LegsConsumer()
{
}

LegsConsumer::LegsConsumer(rclcpp::Node::SharedPtr node)
: LegsConsumer()
{
  set_node(node);
}

void LegsConsumer::set_node(rclcpp::Node::SharedPtr node)
{
  // Initialize the node
  this->node = node;

  // Initialize the position subscription
  {
    position_subscription = get_node()->create_subscription<Position>(
      "/legs/position", 10,
      [this](const Position::SharedPtr position) {
        current_position = *position;
      });

    RCLCPP_INFO_STREAM(
      get_node()->get_logger(),
      "Position subscription initialized on " << position_subscription->get_topic_name() << "!");
  }

  // Initialize the orientation subscription
  {
    orientation_subscription = get_node()->create_subscription<Orientation>(
      "/legs/orientation", 10,
      [this](const Orientation::SharedPtr orientation) {
        current_orientation = *orientation;
      });

    RCLCPP_INFO_STREAM(
      get_node()->get_logger(),
      "Orientation subscription initialized on " <<
        orientation_subscription->get_topic_name() << "!");
  }

  // Initialize the stance subscription
  {
    stance_subscription = get_node()->create_subscription<StanceMsg>(
      "/legs/stance", 10,
      [this](const StanceMsg::SharedPtr msg) {
        current_stance = Stance(*msg);
      });

    RCLCPP_INFO_STREAM(
      get_node()->get_logger(),
      "Stance subscription initialized on " << stance_subscription->get_topic_name() << "!");
  }

  // Initialize the command subscription
  {
    command_subscription = get_node()->create_subscription<StringMsg>(
      "/legs/command", 10,
      [this](const StringMsg::SharedPtr msg) {
        current_command = msg->data;
      });

    RCLCPP_INFO_STREAM(
      get_node()->get_logger(),
      "Command subscription initialized on " << command_subscription->get_topic_name() << "!");
  }
}

rclcpp::Node::SharedPtr LegsConsumer::get_node() const
{
  return node;
}

const Position & LegsConsumer::get_position() const
{
  return current_position;
}

const Orientation & LegsConsumer::get_orientation() const
{
  return current_orientation;
}

const Stance & LegsConsumer::get_stance() const
{
  return current_stance;
}

const std::string & LegsConsumer::get_command() const
{
  return current_command;
}

}  // namespace beine_cpp

#endif  // BEINE_CPP__CONSUMER__LEGS_CONSUMER_HPP_
