class Heap{
    private:
        vector<int> arr;
    public:
        bool empty(){
            return (arr.size() == 0);
        }
        int leftChild(int i){
            return 2*i+1;
        }
        int rightChild(int i){
            return 2*i+2;
        }
        int parent(int i){
            return ((i-1)/2);
        }
        int top(){
            return arr[0];
        }
        void pop(){
            swap(arr[0],arr[arr.size()-1]);
            arr.pop_back();
            topDownHeapify(0);
        }
        void push(int elem){
            arr.push_back(elem);
            bottomUpHeapify(arr.size()-1);
        }
        void bottomUpHeapify(int i){
            if(parent(i)>=0){
                if(arr[i] < arr[parent(i)]){
                    swap(arr[parent(i)],arr[i]);
                    bottomUpHeapify(parent(i));
                }
            }
        }
        void topDownHeapify(int i){
            int min_elem_index = i;
            if(leftChild(i)<arr.size() && arr[leftChild(i)] < arr[min_elem_index])
                min_elem_index = leftChild(i);
            if(rightChild(i)<arr.size() && arr[rightChild(i)] < arr[min_elem_index])
                min_elem_index = rightChild(i);
            if(min_elem_index!=i){
                swap(arr[min_elem_index],arr[i]);
                topDownHeapify(min_elem_index);
            }
        }
        void printHeap(){
            cout<<"Heap : ";
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
