namespace Ariana
{

template<class Itr>
inline static void insert(Itr first, Itr i) {
    auto value = *i;

    Itr j = i;
    while (first < i && *(j - 1) > value) {
        *j = *(j - 1);
        j--;
    }

    *j = value;
}

template<class Itr> // RandomAccessIterator
void insertionSort(Itr first, Itr second) {
    for (Itr i = first + 1; i != second; i++) {
        insert(first, i);
    }
}

}; // namespace