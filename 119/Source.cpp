#include <vector>;

using std::vector;

struct TreeNode
{
	size_t val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(size_t x) : val(x), left(nullptr), right(nullptr) {}
};

//TMP list
template<size_t I, typename as>
struct Cons
{
public:
	static vector<size_t> to_vector()
	{
		vector<size_t> result;
		vector_impl(result);
		return result;
	}

	static void vector_impl(vector<size_t>& c)
	{
		c.push_back(I);
		as::vector_impl(c);
	}
};

struct Nil
{
public:
	static vector<size_t> to_vector()
	{
		return {};
	}

	static void vector_impl(vector<size_t>& c)
	{
	}
};


//get Pascal's Triangle
template<size_t I>
struct pt;

template<>
struct pt<0> { using type = Cons<1, Nil>; };

template<>
struct pt<1> { using type = Cons<1, Cons<1, Nil>>; };

template<typename a>
struct two_sum;

template<size_t I, size_t J>
struct two_sum<Cons<I, Cons<J, Nil>>> { using type = Cons<I + J, Nil>; };

template<size_t I, size_t J, typename as>
struct two_sum<Cons<I, Cons<J, as>>> { using type = Cons<I + J, typename two_sum<Cons<J, as>>::type>; };

//add to the end of list
template<size_t I, typename a>
struct append;

template<size_t I>
struct append<I, Nil> { using type = Cons<I, Nil>; };

template<size_t I, size_t J, typename as>
struct append<I, Cons<J, as>> { using type = Cons<J, typename append<I, as>::type>; };

//add one to both head and tail of list
template<typename a>
struct head_tail { using type = Cons<1, typename append<1, a>::type>; };

template<>
struct head_tail<Nil> { using type = Cons<1, Cons<1, Nil>>; };

template<size_t I>
struct pt { using type = typename head_tail<typename two_sum<typename pt<I - 1>::type>::type>::type; };

class Solution {
public:
	//a bysection search for rowIndex
	vector<size_t> getRow(size_t rowIndex) {
		if (rowIndex == 0) return get<0>();
		//will overflow size_t on 34
		if (rowIndex == 33) return get<33>();
		return bysection<0, 33>(rowIndex);
	}

	template<size_t M, size_t N>
	vector<size_t> bysection(size_t ri)
	{
		constexpr size_t P = (M + N) / 2;
		if (P == ri) return get<P>();
		if (ri < P) return bysection<M, P>(ri);
		return bysection<P, N>(ri);
	}

	template<size_t I>
	vector<size_t> get() {
		return pt<I>::type::to_vector();
	}
};