#include "List.h"
#include <gtest.h>

TEST(Iterator, can_create_iterator)
{
	List<int> a;
	ASSERT_NO_THROW(List<int>::iterator it(a.begin()));
}

TEST(Iterator, copy_constructor_available)
{
	List<int> a;
	List<int>::iterator it_1(a.begin());
	ASSERT_NO_THROW(List<int>::iterator it_2(it_1));
}

TEST(Iterator, operator_of_redeference_available)
{
	List<int> a;
	List<int>::iterator it(a.begin());
	ASSERT_NO_THROW(*it);
}

TEST(Iterator, operator_of_arrowhead_available_and_correct)
{
	List<int> a(21);
	List<int>::iterator it(a.begin());
	ASSERT_NO_THROW(it->data);
	EXPECT_EQ(21, it->data);
}

TEST(Iterator, operator_of_prefix_plus_plus_is_correct)
{
	List<int> a(21);
	a.insert(14, 2);
	List<int>::iterator it(a.begin());
	++it;
	EXPECT_EQ(it->data, 14);

}

TEST(Iterator, operator_of_equal_is_correct)
{
	List<int> a(21);
	List<int>::iterator it_1(a.begin());
	List<int>::iterator it_2(a.begin());
	ASSERT_TRUE(it_1 == it_2);
}

TEST(Iterator, operator_of_not_equal_is_correct)
{
	List<int> a(21);
	a.insert(14, 2);
	List<int>::iterator it_1(a.begin());
	List<int>::iterator it_2(++a.begin());
	ASSERT_TRUE(it_1 != it_2);
}

TEST(List, can_create_int_list_with_head)
{
	ASSERT_NO_THROW(List<int> a);
}

TEST(List, can_create_double_list_with_head)
{
	ASSERT_NO_THROW(List<double> a);
}

TEST(List, constructor_with_parameter_is_available_and_correct)
{
	ASSERT_NO_THROW(List<int> a(21));

	List<int> b(14);
	EXPECT_EQ(14, b.begin()->data);
}

TEST(List, can_insert_in_first_position_index_correctly)
{
	List<int> a; a.insert(2);
	List<int> b(12); b.insert(2);

	EXPECT_EQ(2, a.begin()->data);
	EXPECT_EQ(2, b.begin()->data);

}

TEST(List, can_insert_in_last_position_by_index_correctly)
{
	List<int>a(23); a.insert(24); a.insert(25); a.insert(26);
	a.insert(27, 5);		
	List<int>::iterator it(a.begin());
	for (int i = 1; i < 5; i++)
		++it;

	EXPECT_EQ(27, it->data);

}

TEST(List, can_insert_in_middle_position_by_index_correctly)
{
	List<int>a(23); a.insert(24); a.insert(25); a.insert(26);
	a.insert(9, 3);
	List<int>::iterator it(a.begin());
	for (int i = 1; i < 3; i++)
		++it;

	EXPECT_EQ(9, it->data);
}

TEST(List, throw_then_incorrect_position_insert_by_index)
{
	List<int>a(23);
	ASSERT_ANY_THROW(a.insert(7, 3));	
}

TEST(List, can_insert_by_pointer)
{
	List<int> a(23);
	List<int>::iterator it(a.end());
	ASSERT_NO_THROW(a.insert(5, *it));	
	EXPECT_EQ(5, a.begin()->data);
}

TEST(List, can_erase_element_by_index)
{
	List<int>a(11);
	a.insert(12, 2);
	ASSERT_NO_THROW(a.erase(1));
	EXPECT_EQ(12, a.begin()->data);
}

TEST(List, throw_then_incorrect_position_erase)
{
	List<int> a(-3);
	ASSERT_ANY_THROW(a.erase(5));
}

TEST(List, can_erase_element_by_pointer)
{
	List<int>a(11);
	a.insert(12, 2);
	ASSERT_NO_THROW(a.erase(*a.end()));
	EXPECT_EQ(12, a.begin()->data);
	EXPECT_EQ(1, a.GetCount());
}

TEST(List, throw_then_pointer_for_erase_to_last_element)
{
	List<int> a(-3);
	ASSERT_ANY_THROW(a.erase(*a.begin()));
}

TEST(List, can_search_element_by_value_correctly)
{
	List<int>a(11); a.insert(3); a.insert(7); a.insert(-18); a.insert(4);
	EXPECT_EQ(true, a.search(3));
	EXPECT_EQ(false, a.search(18));
}

TEST(List, can_check_for_emptiness_correctly)
{
	List<int> a(11); a.insert(3);
	EXPECT_EQ(false, a.empty());

	a.erase(1); a.erase(1);
	EXPECT_EQ(true, a.empty());
}

TEST(List, can_return_front_correctly)
{
	List<int> a(43); EXPECT_EQ(43, a.front());
	a.insert(26); EXPECT_EQ(26, a.front());
	a.erase(1); a.erase(1); ASSERT_ANY_THROW(a.front());
}

TEST(List, can_clear_list)
{
	List<int> a(8); a.insert(9); a.insert(10);
	ASSERT_NO_THROW(a.clear());
	EXPECT_EQ(true, a.empty());
}

TEST(List, return_count_of_elements_correctly)
{
	List<int> a; EXPECT_EQ(0, a.GetCount());
	a.insert(6), a.insert(-34); EXPECT_EQ(2, a.GetCount());
	a.clear(); EXPECT_EQ(0, a.GetCount());
}