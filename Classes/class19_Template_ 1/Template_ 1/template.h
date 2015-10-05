#include<iterator>

template<typename Iterator>
size_t counter(Iterator first, Iterator second ){

	return (second - first);


}