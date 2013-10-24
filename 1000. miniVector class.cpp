#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
class miniVector
{
	public:
		miniVector(int size = 0)
		{
		    if (size == 0)
		    vCapacity = 1;
		    else
		    vCapacity = 2 * size;
		    vSize = size;
		    vArr = new T[vCapacity];
		}
			// constructor.
			// Postconditions: allocates array with size number of elements
			// and capacity. elements are initialized to T(), the default
			// value for type T

		miniVector(const miniVector<T>& obj)
		{
            vCapacity = obj.capacity();
		    vSize = obj.size();
            vArr = new T[vCapacity];
            for (int i = 0;i <= vSize;i++)
            {
                vArr[i] = obj[i];
            }
		}
			// copy constructor
			// Postcondition: creates current vector as a copy of obj

		~miniVector()
		{
		    if (vArr != NULL)
		    delete [] vArr;
		}

		miniVector& operator= (const miniVector<T>& rhs)
		{
            vCapacity = rhs.capacity();
		    vSize = rhs.size();
		    if (vArr != NULL)
            delete [] vArr;
            vArr = new T[vCapacity];
            for (int i = 0;i < vSize;i++)
            {
                vArr[i] = rhs[i];
            }
		}
		T& back()
		{
		    if (vSize != 0)
		    {
		        return vArr[vSize-1];
		    }
		}
			// return the element at the rear of the vector.
			// Precondition: the vector is not empty. if vector
			// is empty, do nothing.

		const T& back() const
		{
		    if (vSize != 0)
		    {
		        return vArr[vSize-1];
		    }
		}
			// const version used when miniVector object is a constant

		T& operator[] (int i)
		{
		    if (i >= 0 && i < vSize)
		    return vArr[i];
		}
			// provides general access to elements using an index.
			// Precondition: 0 <= i < vSize. if the index is out
			// of range, do nothing.

		const T& operator[] (int i) const
		{
		    if (i >= 0 && i < vSize)
		    return vArr[i];
		}
			// const version used when miniVector object is a constant

		void push_back(const T& item)
		{
		    if (vSize >= vCapacity)
		    {
		        vCapacity *= 2;
		        T * temp = new T [vCapacity];
		        for (int i = 0;i < vSize;i++)
		        {
		            temp[i] = vArr[i];
		        }

		        vArr = temp;
		    }
		    vArr[vSize++] = item;

		}
			// insert item at the rear of the vector.
			// Postcondition: the vector size is increased by 1

		void pop_back()
		{
		    if (vSize!= 0)
		    {
		        vSize--;
                if (vSize <= vCapacity / 4)
                {
                    vCapacity /= 2;
                    T * temp = new T [vCapacity];
                    for (int i = 0;i < vSize;i++)
                    {
                        temp[i] = vArr[i];
                    }

                    vArr = temp;
                }
		    }
		}
			// remove element at the rear of the vector.
			// Precondition: vector is not empty. if the vector is
			// empty, do nothing.

		void insert(const T& item, int k)
		{
		    if (k >= 0 && k <= vSize)
		    {
		        if(vSize == vCapacity)
                {
                    vSize++;
                    vCapacity *= 2;
                    T * temp = new T [vCapacity];
                    if (k != vSize - 1)
                    {
                        for (int i = 0;i < k;i++)
                        {
                            temp[i] = vArr[i];
                        }
                        temp[k] = item;
                        for (int i = k + 1;i < vSize;i++)
                        {
                        temp[i] = vArr[i-1];
                        }
                    }
                    else
                    {
                        for (int i = 0;i < k;i++)
                        {
                            temp[i] = vArr[i];
                        }
                        temp[k] = item;
                    }

                    delete [] vArr;
                    vArr = temp;

                }
                else
                {
                    if (k !=vSize)
                    {
                        for (int i = vSize - 1;i >=k;i--)
                        {
                            vArr[i+1] = vArr[i];
                        }
                    }
                    vArr[k] = item;
                    vSize++;
                }
		    }
		}

        void remove(int k)
        {
            if (k >= 0 && k < vSize)
            {
                for (int i = k+1;i < vSize;i++)
                {
                vArr[i-1] = vArr[i];

                }
                vSize--;
                if (vSize <= vCapacity / 4)
                {
		        vCapacity /= 2;
		        T * temp = new T [vCapacity];
		        for (int i = 0;i < vSize;i++)
		        {
		            temp[i] = vArr[i];
		        }
		        delete [] vArr;
		        vArr = temp;
                }
            }
        }
			// remove element at the k position of the vector, 0¡Ük ¡ÜvSize-1.
			// Precondition: vector is not empty.
            // If the vector is empty, or k out of range, do nothing.


		int size() const
		{
		    return vSize;
		}

		bool empty() const
		{
		    return (vSize == 0);
		}

		int capacity() const
		{
		    return vCapacity;
		}

   private:
		int vCapacity;		// amount of available space
		int vSize;			// number of elements in the list
		T *vArr;				// the dynamic array

		void reserve(int n, bool copy);
			// called by public functions only if n > vCapacity. expands
			// the vector capacity to n elements, copies the existing
			// elements to the new space if copy == true, and deletes
			// the old dynamic array.
};

// set the capacity to n elements
template <typename T>
void miniVector<T>::reserve(int n, bool copy)
{
	T *newArr;
	int i;

	// allocate a new dynamic array with n elements
	newArr = new T[n];

	// if copy is true, copy elements from the old list to the new list
	if (copy)
		for(i = 0; i < vSize; i++)
			newArr[i] = vArr[i];

	// delete original dynamic array. if vArr is NULL, the vector was
	// originally empty and there is no memory to delete
	if (vArr != NULL)
		delete [] vArr;

	// set vArr to the value newArr. update vCapacity
	vArr = newArr;
	vCapacity = n;
}
int main()
{
    miniVector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.insert(3,2);
    a.push_back(1);
    a.push_back(2);
    a.insert(3,2);
    a.push_back(1);
    a.push_back(2);
    a.insert(3,2);
    miniVector<int> b(a);
    cout<<a.size()<<" "<<a.capacity()<<" "<<a.back()<<" "<<a.empty()<<endl;
    cout<<a.back()<<endl;
    a.pop_back();
    cout<<a.back()<<endl;
    a.pop_back();
    cout<<a.back()<<endl;
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();


    cout<<a.capacity()<<" "<<a.size()<<" "<<a.empty()<<endl;
    cout<<b.size()<<" "<<b.capacity()<<" "<<b.back()<<" "<<b.empty()<<endl;
    cout<<b.back()<<endl;
    b.pop_back();
    cout<<b.back()<<endl;
    b.remove(1);
    cout<<b.back()<<endl;
    b.pop_back();
    cout<<b.capacity()<<" "<<b.empty();
}
