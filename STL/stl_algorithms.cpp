    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int arr[] = {10, 20, 5, 23, 42, 15, 20};
        int n = sizeof(arr)/sizeof(arr[0]);
        vector<int> vect(arr, arr+n);

        cout << "Vector is: ";
        for (int i=0; i<n; i++)
            cout << vect[i] << " ";

        sort(vect.begin(), vect.end());

        cout << "\nVector after sorting is: ";
        for (int i=0; i<n; i++)
           cout << vect[i] << " ";

        reverse(vect.begin(), vect.end());

        cout << "\nVector after reversing is: ";
        for (int i=0; i<n; i++)
            cout << vect[i] << " ";

        cout << "\nMaximum element of vector is: ";
        cout << *max_element(vect.begin(), vect.end());

        cout << "\nMinimum element of vector is: ";
        cout << *min_element(vect.begin(), vect.end());

        cout << "\nThe summation of vector elements is: ";
        cout << accumulate(vect.begin(), vect.end(), 0)<<endl;

        cout << "Occurrences of 20 in vector : ";

        cout << count(vect.begin(), vect.end(), 20);

        find(vect.begin(), vect.end(),5) != vect.end() ? cout << "\nElement found\n":cout << "\nElement not found\n";

        sort(vect.begin(),vect.end());

        auto q = lower_bound(vect.begin(), vect.end(), 20);

        auto p = upper_bound(vect.begin(), vect.end(), 20);

        cout << "The lower bound is at position: ";
        cout << q-vect.begin() << endl;

        cout << "The upper bound is at position: ";
        cout << p-vect.begin() << endl;

        cout << "Vector is :";
        for (int i=0; i<n; i++)
            cout << vect[i]<<" ";

        // Deletes the second element of the vector
        vect.erase(vect.begin()+1);

        cout << "\nVector after erasing the element: ";
        for (unsigned int i=0; i<vect.size(); i++)
            cout << vect[i] << " ";

        sort(vect.begin(), vect.end());

        cout << "\nVector before removing duplicate occurrences: ";
        for (unsigned int i=0; i<vect.size(); i++)
            cout << vect[i] << " ";

        // Deletes duplicate occurrences
        vect.erase(unique(vect.begin(),vect.end()),vect.end());

        cout << "\nVector after deleting duplicates: ";
        for (unsigned int i=0; i< vect.size(); i++)
            cout << vect[i] << " ";

        return 0;
    }
