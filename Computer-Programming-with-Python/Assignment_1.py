""" question 1."""
# def sortByLast(arr):
#     return arr.sort(key = lambda x: x[-1])

# arr = [(2, 5), (1, 2), (4, 4), (2, 3), (2, 1)]
# sortByLast(arr)
# print(arr)

# """ question 2. """

# def replace_chars(s):
#     if not s:
#         return s
#     first_char = s[0]
#     # Replace all occurrences of first_char with '$' except the first one
#     replaced_string = first_char + s[1:].replace(first_char, '$')
#     return replaced_string


# # Sample input
# sample_string = 'restartr'
# result = replace_chars(sample_string)
# print(result)

""" question 3."""

# def not_poor(s):
#     not_pos = s.find('not')
#     poor_pos = s.find('poor')

#     # Check if 'not' comes before 'poor' and both exist in the string
#     if not_pos != -1 and poor_pos != -1 and not_pos < poor_pos:
#         # Replace 'not'...'poor' substring with 'good'
#         s = s[:not_pos] + 'good' + s[poor_pos + 4:]  # 4 is length of 'poor'
#     return s

# # Example usage:
# sample_string = "The movie is not that poor!"
# s = "The lyrics is not that poor!"
# result = not_poor(sample_string)
# print(not_poor(s))
# print(result)

""" question 4."""

# def sort_dict_by_value(d):
#     # Sort the dictionary by value and return a new dictionary
#     sorted_dict = dict(sorted(d.items(), key=lambda item: item[1]))
#     return sorted_dict

# # Example usage
# sample_dict = {'apple': 3, 'banana': 1, 'cherry': 5, 'date': 2}
# sorted_result = sort_dict_by_value(sample_dict)
# print(sorted_result)


""" question 5."""
# Existing dictionary
my_dict = {1: 'apple', 2: 'banana'}

# New key-value to add
new_key = 3
new_value = 'cherry'

# Add the new key-value pair
my_dict[new_key] = new_value

# Print updated dictionary
print(my_dict)
