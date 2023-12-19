int AbsSum(int* Start, int Count)
{
	if (Count <= 0)
		return 0;
	int Value = *Start + rSum(Start + 1, Count - 1);
	return Value < 0 ? -Value : Value;
}