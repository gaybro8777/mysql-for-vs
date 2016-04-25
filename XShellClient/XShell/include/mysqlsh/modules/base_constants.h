/*
   Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved.














   The lines above are intentionally left blank
*/

// Interactive Expression access module
// Exposed as "Expression" in the shell

#ifndef _BASE_CONSTANT_H_
#define _BASE_CONSTANT_H_

#include "mod_common.h"
#include "shellcore/types.h"
#include "shellcore/types_cpp.h"
#include "shellcore/ishell_core.h"

namespace mysh
{
  class SHCORE_PUBLIC Constant : public shcore::Cpp_object_bridge
  {
  public:
    Constant(const shcore::Value &data);
    Constant(const std::string &module, const std::string &group, const std::string &id, const shcore::Argument_list &args);
    virtual ~Constant() {};

    // Virtual methods from object bridge
    virtual std::string class_name() const { return "Constant"; };
    virtual bool operator == (const Object_bridge &other) const;
    virtual std::string &append_descr(std::string &s_out, int indent, int quote_strings) const;

    virtual shcore::Value get_member(const std::string &prop) const;
    std::vector<std::string> get_members() const;

    std::string group() { return _group; }
    std::string id() { return _id; }
    shcore::Value data() { return _data; }

    static shcore::Value get_constant(const std::string &module, const std::string& group, const std::string& id, const shcore::Argument_list &args);

    void set_param(const std::string& data);

    shcore::Value get_data() { return _data; };

  private:
    std::string _module;
    std::string _group;
    std::string _id;
    shcore::Value _data;

    shcore::Value get_constant_value(const std::string &module, const std::string& group, const std::string& id, const shcore::Argument_list &args);

    // A single instance of every Constant will exist
    typedef std::map<std::string, boost::shared_ptr<Constant> > Group_constants;
    typedef std::map<std::string, Group_constants> Module_constants;
    static std::map<std::string, Module_constants> _constants;
  };
};

#endif
