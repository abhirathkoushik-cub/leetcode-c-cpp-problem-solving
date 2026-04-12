#include <stdio.h>
#include<stdint.h>

#define CAPACITY 4 // Capacity must be a power of 2 for the bitwise operations to work correctly

typedef struct {
    uint32_t buf[CAPACITY];
    uint32_t front;
    uint32_t rear;
    uint8_t size;
} RingBuf;

void push_in_buffer(RingBuf* arr, uint32_t element)
{
  if (arr->size == CAPACITY)
  {
    printf("Buffer is full, cannot push\n");
    return;
  }

  arr->rear = (arr->rear + 1) & (CAPACITY - 1);
  arr->buf[arr->rear] = element;
  arr->size++;
}

int pop_from_buffer(RingBuf* arr, uint32_t* data)
{
  if(arr->size == 0)
  {
    printf("Buffer is empty, nothing to pop\n");
    return -1;
  }
  *data = arr->buf[arr->front];
  arr->front = (arr->front + 1) & (CAPACITY - 1);
  arr->size--;
  return 0;
}

void display_buffer(RingBuf* arr)
{
  for(int i=0;i<CAPACITY;i++)
  {
    printf("%d-", arr->buf[i]);
  }
  printf("\n");
}

int main()
{
  RingBuf rx_buf;
  rx_buf.front=0;
  rx_buf.rear=-1; // rear starts at -1 (INT_MAX as uint32_t) as the first push will increment it to 0
  rx_buf.size=0;

  push_in_buffer(&rx_buf, 8);
  push_in_buffer(&rx_buf, 10);
  push_in_buffer(&rx_buf, 12);
  push_in_buffer(&rx_buf, 14);
  push_in_buffer(&rx_buf, 16); // This will not be added to the buffer as it is full

  uint32_t pop_elem;
  pop_from_buffer(&rx_buf, &pop_elem); 
  push_in_buffer(&rx_buf, 16); // Now this will be added to the buffer as we popped one element out
  
  RingBuf tx_buf;
  tx_buf.front=0;
  tx_buf.rear=-1;
  tx_buf.size=0;
  push_in_buffer(&tx_buf, pop_elem); // Popped element from rx_buf is added to tx_buf

  display_buffer(&rx_buf);
  display_buffer(&tx_buf);
}
