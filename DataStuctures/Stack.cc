
template <typename T>
class Stack
{
public:
  // Add an element to the top of the stack
  void push(const T &value)
  {
    data.push_back(value);
  }

  // Remove and return the top element from the stack
  T pop()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Cannot pop from an empty stack");
    }
    T value = data.back();
    data.pop_back();
    return value;
  }

  // Return a reference to the top element of the stack
  const T &top() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Cannot get the top of an empty stack");
    }
    return data.back();
  }

  // Check if the stack is empty
  bool isEmpty() const
  {
    return data.empty();
  }

private:
  std::vector<T> data;
};
