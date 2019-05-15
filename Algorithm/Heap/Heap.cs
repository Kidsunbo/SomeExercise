using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Heap_Test
{
    
    class Heap
    {
        private bool _isMaxHeap = true;
        private List<int> _heap = new List<int>();
        public Heap(bool maxHeap,params int[] args)
        {
            _isMaxHeap = maxHeap;
            foreach(var i in args)
            {
                insert(i);
            }
        }

        private void insertMax(int v)
        {
            _heap.Add(v);

            bubbleUpMax(_heap.Count - 1);

        }

        private void insertMin(int v)
        {
            _heap.Add(v);
            bubbleUpMin(_heap.Count - 1);
        }

        public void insert(int v)
        {
            if (_isMaxHeap)
            {
                insertMax(v);
            }
            else
            {
                insertMin(v);
            }
        }

        private void deleteMax()
        {
            if (_heap.Count == 0) throw new Exception("Empty");
            _heap[0] = _heap.Last();
            _heap.RemoveAt(_heap.Count - 1);
            bubbleDownMax(0);
        }

        private void deleteMin()
        {
            if (_heap.Count == 0) throw new Exception("Empty");
            _heap[0] = _heap.Last();
            _heap.RemoveAt(_heap.Count - 1);
            bubbleDownMin(0);
        }

        public void delete()
        {
            if (_isMaxHeap)
                deleteMax();
            else deleteMin();
        }

        private void bubbleUpMax(int index)
        {
            if (index == 0) return;
            var target = (index-1) / 2;

            if (_heap[index] > _heap[target])
            {
                swap(target, index);
                bubbleUpMax(target);
            }

        }

        private void bubbleUpMin(int index)
        {
            if (index == 0) return;

            var target = (index - 1) / 2;
            if (_heap[index] < _heap[target])
            {
                swap(target, index);
                bubbleDownMax(target);
            }
        }
        private void bubbleDownMax(int index)
        {
            var target1 = index * 2 + 1;
            var target2 = index * 2 + 2;
            if (target2 >= _heap.Count) return;

            if (_heap[index] < _heap[target1] || _heap[index]<_heap[target2])
            {
                if (_heap[target1] < _heap[target2])
                {
                    swap(target2, index);
                    bubbleDownMax(target2);
                }
                else
                {
                    swap(target1, index);
                    bubbleDownMax(target1);
                }

            }
        }

        private void bubbleDownMin(int index)
        {
            var target1 = index * 2 + 1;
            var target2 = index * 2 + 2;
            if (target2 >= _heap.Count) return;
            if (_heap[index] > _heap[target1] || _heap[index] > _heap[target2])
            {
                if (_heap[target1] > _heap[target2])
                {
                    swap(target2, index);
                    bubbleDownMax(target2);
                }
                else
                {
                    swap(target1, index);
                    bubbleDownMax(target1);
                }
            }
        }
        private void swap(int a, int b)
        {
            int temp = _heap[a];
            _heap[a] = _heap[b];
            _heap[b] = temp;
        }

        /*
               0
            1     2
           3 4   5 6


        */
        public void print()
        {
            var count = 0;
            var depth = 1;
            for (var i = 0; i < _heap.Count; i++)
            {
                Console.Write($"{_heap[i]}  ");
                if (i == count)
                {
                    count += (int)Math.Pow(2, depth++);
                    Console.WriteLine();
                }
            }
            Console.WriteLine();

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Heap p = new Heap(true, 1,2,3,4,5,6,7,8,9);
            p.print();
            Console.WriteLine();
            p.delete();
            p.print();
            Console.WriteLine();
            p.delete();
            p.print();
            Console.WriteLine();
            p.insert(5);
            p.print();
            Console.WriteLine();
            p.insert(6);
            p.print();
            Console.WriteLine();
            p.insert(3);
            p.print();
            Console.Read();
        }
    }
}
