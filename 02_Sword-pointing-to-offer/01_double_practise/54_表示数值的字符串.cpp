

/*
 * Date:2021-08-26 21:35
 * filename:54_表示数值的字符串.cpp
 *
 */

bool isNumeric(char* string) {
	bool isExponential(char** string);
	void scanDigits(char** string);
	if (string == NULL)
		return false;

	if (*string == '+' || *string == '-') 
		++string;
	if (*string == '\0')
		return false;

	bool numeric = true;
	scanDigits(&string);
	if (*string != '\0') {
		//for floats
		if (*string == '.') {
			++string;
			scanDigits(&string);
			if (*string == 'e' || *string == 'E') 
				numeric = isExponential(&string);
		}
		else if (*string == 'e' || *string == 'E')
			numeric = isExponential(&string);
		else
			numeric = false;
	}
	return numeric && *string == '\0';
}

void scanDigits(char** string) {
	while (**string != '\0' && **string >= '0' && **string <= '9')
		++(*string);
}

bool isExponential(char** string) {
	if (**string != 'e' && **string != 'E')
		return false;

	++(*string);
	if (**string == '+' || **string == '-')
		++(*string);

	if (**string == '\0')
		return false;

	scanDigits(string);
	return (**string =='\0') ? true : false;
}
