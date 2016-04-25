/*
   Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved.














   The lines above are intentionally left blank
*/


#ifndef _NGS_ASIO_CALLBACK_H_
#define _NGS_ASIO_CALLBACK_H_


#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include "myasio/types.h"


namespace ngs
{


class Callback
{
public:
  virtual ~Callback() {}

  virtual void call_data_function(On_asio_data_callback &data_function, const int received_data = 0) = 0;
  virtual void call_data_function(On_asio_data_callback &data_function, const boost::system::error_code &error, const int received_data = 0) = 0;
  virtual void call_status_function(On_asio_status_callback &status_function, const boost::system::error_code &error = boost::system::error_code()) = 0;
};


typedef boost::shared_ptr<Callback> Callback_ptr;


class Callback_direct : public Callback
{
public:
  void call_data_function(On_asio_data_callback &data_function, const int received_data = 0);
  void call_data_function(On_asio_data_callback &data_function, const boost::system::error_code &error, const int received_data = 0);
  void call_status_function(On_asio_status_callback &status_function, const boost::system::error_code &error = boost::system::error_code());
};


typedef boost::function<void (const boost::function<void ()> &)>  Function_post;


class Callback_post : public Callback
{
public:
  Callback_post(const Function_post &post);

  void call_data_function(On_asio_data_callback &data_function, const int received_data = 0);
  void call_data_function(On_asio_data_callback &data_function, const boost::system::error_code &error, const int received_data = 0);
  void call_status_function(On_asio_status_callback &status_function, const boost::system::error_code &error = boost::system::error_code());

private:
  Function_post m_post;
};


} // namespace ngs

#endif // _NGS_ASIO_CALLBACK_H_
