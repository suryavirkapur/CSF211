
int binary_search(std::vector<int> v, int a)
{
  std::sort(v.begin(), v.end());
  int maximum = (v.size()) - 1;
  int minimum = 0;
  int mean;

  while (maximum > minimum)
  {
    mean = (maximum + minimum) / 2;
    if (v[mean] == a)
    {
      return mean;
    }
    else if (v[mean] > a)
    {
      maximum = (mean - 1);
    }
    else
    {
      minimum = (mean + 1);
    }
  }
  return -1;
}