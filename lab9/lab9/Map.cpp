#include <iostream>
template <typename K, typename V>
class Map
{
public:
    struct Element
    {
        K key;
        V value;
        int index;
    };
private:
    Element elements[100];
    int nr;
public:
    Map()
    {
        nr = 0;
    }
    Element* begin() { return &elements[0]; }
    Element* end() { return &elements[nr]; }
    V& operator [](K x)
    {
        for (int i = 0;i < nr;i++)
            if (elements[i].key == x)
                return elements[i].value;
        elements[nr].key = x;
        elements[nr].index = nr;
        nr++;
        return elements[nr - 1].value;
    }
    void Set(K& x, V& y)
    {
        for (int i = 0;i < nr;i++)
            if (elements[i].key == x)
            {
                elements[i].value = y; return;
            }
        elements[nr].key = x;
        elements[nr].value = y;
        elements[nr].index = nr;
        nr++;
    }
    bool Get(K& k, V& v)
    {
        for (int i = 0;i < nr;i++)
        {
            if (elements[i].key == k)
            {
                v = elements[i].value;return true;
            }
        }
        return false;
    }
    int Count()
    {
        return nr;
    }
    void Clear() {
        nr = 0;
    }
    bool Delete(K& key)
    {
        for (int i = 0;i < nr;i++)
        {
            if (elements[i].key == key)
            {
                for (int j = i;j < nr - 1;j++)
                {
                    elements[j] = elements[j + 1];
                    elements[j].index--;
                }
                nr--;
                return true;
            }
        }
        return false;
    }
    bool Includes(Map<K, V>& map)
    {
        for (int i = 0; i < map.nr; i++) {
            bool gasit = false;
            for (int j = 0; j < nr; j++) {
                if (this->elements[j].key == map.elements[i].key) {
                    gasit = true;
                    break;
                }
            }
            if (!gasit)
                return false;
        }
        return true;
    }
};
int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}