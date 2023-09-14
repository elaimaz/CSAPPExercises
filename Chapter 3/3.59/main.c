int switch_prob(int x, int n)
{
	int result = x;

	switch (n)
	{
	case 32:
	case 34:
		result <<= 2;
		break;
	case 35:
		result >>= 2;
		break;
	case 36:
		result += (result * 2);
	case 37:
		result *= result;
	default:
		result += 10;
	}

	return result;
}

int main() {
    return 0;
}