#include "base_conversion.h"
#include <iostream>


int base_conversion::binary_string_to_integer(const char * a_binary_string)
{
	int bit_field = 0;
	size_t string_length = strlen(a_binary_string);
	
	for (size_t i = 0; i < string_length; i++)
	{
		if (a_binary_string[i] == '1')
		{
			set_bit(bit_field, char(string_length) - char(i) - 1, true);
		}
	}

	return bit_field;
}

void base_conversion::integer_to_binary_string(char * a_binary_string, int value)
{
	a_binary_string[32] = '\0';

	for (size_t i = 0; i < 32; i++)
	{
		a_binary_string[31 - i] = get_bit(value, char(i)) ? '1' : '0';
	}
}

void base_conversion::set_bit(int & a_bit_field, char a_bit_index, bool a_state)
{
	// Shift OR = on
	if (a_state)
	{
		a_bit_field = a_bit_field | (1 << a_bit_index);
	}
	// shift Flip AND = off
	else
	{
		a_bit_field = a_bit_field & ~(1 << a_bit_index);
	}


}

bool base_conversion::get_bit(const int & a_bit_field, char a_bit_index)
{
	return bool(a_bit_field & (1 << a_bit_index));

	return false;
}

void base_conversion::print_int_as_binary(const int a_bit_field, bool a_spaced)
{
	for (int i = 31; i >= 0; i--)
	{
		std::cout << base_conversion::get_bit(a_bit_field, i);
		if (a_spaced && i % 4 == 0)
		{
			std::cout << " ";
		}
	}
	std::cout << '\n';
}
