#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one) // Скопированный вектор равен первому
{
	TVector<int> v1(10, 2);
	TVector<int> v2(v1);
	EXPECT_EQ(v1, v2);

}

TEST(TVector, copied_vector_has_its_own_memory) // Скопированный вектор имеет собственную память
{
	TVector<int> v1(10, 2);
	TVector<int> v2(v1);
	EXPECT_NE(&v1, &v2);

}

TEST(TVector, can_get_size) // Возможность получить вектор 
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index) // Можем получить начальный индекс
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element) // Можно установить и получить элемент
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index) // Ошибка при установке элемментас отрицательным индексом
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_set_element_with_too_large_index) // Ошибка при установке элемента с превышающим индексом
{
	ASSERT_ANY_THROW(TVector<int> v(10000000000000));
}

TEST(TVector, can_assign_vector_to_itself) 
{
	TVector<int> v(5);
	ASSERT_NO_THROW(v == v);
}

TEST(TVector, can_assign_vectors_of_equal_size) // Можно назначить векторы одинакового размера 
{
	TVector<int> v1(4), v2(4);
	v1[2] = 4;
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size) // Назначить оператор изменения размера вектора
{
	TVector<int> v1(4), v2(5);
	v1 = v2;
	EXPECT_EQ(v1.GetSize(), 5);
}

TEST(TVector, can_assign_vectors_of_different_size) // Можно назначить векторы разного размера
{
	TVector<int> v1(4), v2(5);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, compare_equal_vectors_return_true) // сравнить разные вектора
{
	TVector<int> v1(4), v2(4);
	v1[2] = 4;
	v2[2] = 4;
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true) // Сравнить вектор с самим собой
{
	TVector<int> v(4);
	v[2] = 4;
	ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal) // Векторы разных размеров не равны
{
	TVector<int> v1(4), v2(5);
	ASSERT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector) // Можно прибавить скаляр к вектору
{
	TVector<int> v1(4), v2(4);
	for (int i = 0; i < 4; i++)
		v1[i] = 1;
	EXPECT_EQ(v1, v2 + 1);
}

TEST(TVector, can_subtract_scalar_from_vector) // Можно вычесть скаляр из вектора
{
	TVector<int> v1(4), v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 4;
		v2[i] = 5;
	}
	EXPECT_EQ(v1, v2 - 1);
}

TEST(TVector, can_multiply_scalar_by_vector) // Можно умножить скаляр на вектор
{
	TVector<int> v1(4), v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 16;
		v2[i] = 4;
	}
	EXPECT_EQ(v1, v2 * 4);
}

TEST(TVector, can_add_vectors_with_equal_size) // Можно складывать векторы одинаковых размеров
{
	TVector<int> v1(4), v2(4);
	ASSERT_NO_THROW(v1+v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size) // Нельзя складывать векторы разных размеров
{
	TVector<int> v1(4), v2(5);
	ASSERT_ANY_THROW(v1+v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size) // Можно вычитать векторы одинаковых размеров
{
	TVector<int> v1(4), v2(4);
	ASSERT_NO_THROW(v1-v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) // Нельзя вычитать векторы разных размеров
{
	TVector<int> v1(4), v2(5);
	ASSERT_ANY_THROW(v1-v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size) // Можно умножать векторы одинаковых размеров 
{
	TVector<int> v1(4), v2(4);
	ASSERT_NO_THROW(v1*v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size) // Нельзя умножать векторы разных размеров
{
	TVector<int> v1(4), v2(5);
	ASSERT_ANY_THROW(v1*v2);
}

