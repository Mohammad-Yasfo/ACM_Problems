/*
Queues maintain first-in, first-out order. This appears fairer than last-in, first-out, which
is why lines at stores are organized as queues instead of stacks. Decks of playing cards
can be modeled by queues, since we deal the cards off the top of the deck and add them
back in at the bottom. FIFO queues will be used in implementing breadth-first search
in graphs in Chapter 9.
The abstract operations on a queue include —
• Enqueue(x,q) — Insert item x at the back of queue q.
• Dequeue(q) — Return (and remove) the front item from queue q
• Initialize(q), Full(q), Empty(q) — Analogous to these operation on stacks.
Queues are more difficult to implement than stacks, because action happens at both
ends. The simplest implementation uses an array, inserting new elements at one end
and moving all remaining elements to fill the empty space created on each dequeue.
However, it is very wasteful to move all the elements on each dequeue. How can we
do better? We can maintain indices to the first (head) and last (tail) elements in the
2.1. Elementary Data Structures 29
array/queue and do all operations locally. There is no reason why we must explicitly
clear previously used cells, although we leave a trail of garbage behind the previously
dequeued items.
Circular queues let us reuse this empty space. Note that the pointer to the front of
the list is always behind the back pointer! When the queue is full, the two indices will
point to neighboring or identical elements. There are several possible ways to adjust the
indices for circular queues. All are tricky! The easiest solution distinguishes full from
empty by maintaining a count of how many elements exist in the queue:
*/
typedef struct {
int q[QUEUESIZE+1]; /* body of queue */
int first; /* position of first element */
int last; /* position of last element */
int count; /* number of queue elements */
} queue;
init_queue(queue *q)
{
q->first = 0;
q->last = QUEUESIZE-1;
q->count = 0;
}
enqueue(queue *q, int x)
{
if (q->count >= QUEUESIZE)
printf("Warning: queue overflow enqueue x=%d\n",x);
else {
q->last = (q->last+1) % QUEUESIZE;
q->q[ q->last ] = x;
q->count = q->count + 1;
}
}
int dequeue(queue *q)
{
int x;
if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
else {
x = q->q[ q->first ];
q->first = (q->first+1) % QUEUESIZE;
q->count = q->count - 1;
}
return(x);
}
int empty(queue *q)
{
if (q->count <= 0) return (TRUE);
else return (FALSE);
}