#ifndef SWIG_CGAL_SPATIAL_SEARCHING_KD_TREE_H
#define SWIG_CGAL_SPATIAL_SEARCHING_KD_TREE_H


#include "../Common/Macros.h"
#include "../Common/Input_iterator.h"

#ifdef SWIGPYTHON
#include "../Python/Input_iterator_wrapper.h"
#include "../Python/Output_iterator_wrapper.h"
#endif
#ifdef SWIGJAVA
#include "../Java/Input_iterator_wrapper.h"
#include "../Java/Output_iterator_wrapper.h"
#endif


DECLARE_ITERATOR_CLASS_2(iterator,Kd_tree_iterator)

template <class Query>
struct Query_iterator_helper{
  typedef std::pair<Input_iterator_wrapper<Query,typename Query::cpp_base>,Input_iterator_wrapper<Query,typename Query::cpp_base> > input;
  typedef boost::function_output_iterator< Container_writer<Query,typename Query::cpp_base> >                                       output;
};

template<class Cpp_base, class Query, class Fuzzy_sphere, class Fuzzy_iso_box>
class Kd_tree_wrapper{
  Cpp_base data;
public:
  typedef Cpp_base cpp_base;
  typedef Kd_tree_iterator<Cpp_base,Query> Iterator;
  typedef Query Point_d;
//Input iterator
  typedef typename Query_iterator_helper<Query>::input       Point_range; 
//Output iterator
  typedef typename Query_iterator_helper<Query>::output      Point_d_Output_iterator;


  const cpp_base& get_data() const {return data;}
  cpp_base& get_data_ref() {return data;}

//Operations
  FORWARD_CALL_1(void,insert,Point_d)
  void insert_range(Point_range range){ data.insert(range.first,range.second);}
  Iterator iterator(){return Iterator(data.begin(),data.end());}
  FORWARD_CALL_0(void,clear)
  FORWARD_CALL_0(int,size)
  void search_sphere(Point_d_Output_iterator out, const Fuzzy_sphere& fsphere) { data.search(out,fsphere.get_data());}
  void search_box(Point_d_Output_iterator out, const Fuzzy_iso_box& fbox)   { data.search(out,fbox.get_data());}
};


#endif //SWIG_CGAL_SPATIAL_SEARCHING_KD_TREE_H

//Creation
// Kd_tree<Traits, Splitter, UseExtendedNode> tree ( Splitter s=Splitter());
// template <class InputIterator> Kd_tree<Traits, Splitter, UseExtendedNode> tree ( InputIterator first, InputIterator beyond, Splitter s=Splitter());
//Operations
//  FORWARD_CALL_0(Node_handle,root)
// Kd_tree_rectangle<Traits>  tree.bounding_box ()  
// std::ostream&  tree.statistics ( std::ostream& s)