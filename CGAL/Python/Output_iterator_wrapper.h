#ifndef CGAL_SWIG_PYTHON_OUTPUT_ITERATOR_WRAPPER_H
#define CGAL_SWIG_PYTHON_OUTPUT_ITERATOR_WRAPPER_H

#include "exceptions.h"

template<class Cpp_wrapper,class Cpp_base>
class Container_writer{
  PyObject* list;
  swig_type_info* type;
  
public:

  Container_writer(){}
  Container_writer(PyObject * list_,swig_type_info* type_):list(list_),type(type_)
  {
    CGAL_precondition(PyList_Check(list));//properly handle by a typecheck in SWIG macro
  }
 
  void operator()(const Cpp_base& new_base) {
    Cpp_base* result = new Cpp_base(new_base);
    PyObject* py_object= SWIG_NewPointerObj(SWIG_as_voidptr(result), type, 1);
    assert(py_object!=NULL);
    Py_DECREF(py_object);
    PyList_Append(list,py_object);
  }
};



#endif// CGAL_SWIG_PYTHON_OUTPUT_ITERATOR_WRAPPER_H

