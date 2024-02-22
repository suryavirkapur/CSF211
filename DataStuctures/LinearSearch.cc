
int linear_search(std::vector<int> v, int a)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == a)
      return i;
  }
  return -1;
}
