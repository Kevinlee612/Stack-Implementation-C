#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

// Edit only after this line //

// pop function for stack
Element* pop(Stack* s){
	if (s->top ==-1)return NULL;
	if (s->shrinkFactor!=0 && s->top <= s->capacity*s->shrinkFactor){
		s->capacity*= 0.5;
		s->elements= (struct Element**) realloc(s->elements,s->capacity *sizeof(Element));
	}
	struct Element* temp;
	temp = s->elements[s->top];
	s->elements[s--->top]=NULL;
	return temp;
}

// multipop: pop multiple elements from stack
Element** multiPop(Stack* s, int k){
	if (s->top ==-1)return NULL;
	struct Element** temp;
	if (s->top < k) {
		for (int i=0;i<s->top+1;i++) temp[i]=pop(s);
		return temp;
	}
	for (int i=0;i<k;i++){
		for (int i=0;i<k;i++) temp[i]=pop(s);
	}
	return temp;
}

// Utility function: add element for push
// This function is a hint, you may ignore its implementation
void addE(Stack* s, int k, char* v) {
	struct Element* temp;
	temp->key=k;
	temp->value=v;
	s->elements[++s->top]=temp;
}

// Utility function: expandCapacity for push
// This function is a hint, you may ignore its implementation
void expandCapacity(Stack* s) {
	s->capacity *= 2;
	s->elements = (struct Element**) realloc(s->elements,s->capacity*sizeof(Element));
}

// push function for stack
bool push(Stack* s, int k, char* v){
	if (s->top+1 == s->capacity && s->growthFactor==0) return false;
	if (s->growthFactor != 0 && s->top >= s->capacity*s->growthFactor)
		expandCapacity(s);
	addE(s,k,v);
	return true;
}

// push unique function for stack
bool pushUnique(Stack* s, int k, char* v){
	if (s->top+1 == s->capacity && s->growthFactor==0)return false;
	if (s->elements[s->top]->value != v) {
		push(s,k,v);
		return true;
	}
	return false;
}

// reverse the elements in stack
void reverse(Stack* s){
	struct Element* temp;
	int end = s->top-1;
	int start = 0;
	while(start<end){
	        temp = s->elements[start];
	        s->elements[start] = s->elements[end];
	        s->elements[end] = temp;
	        start++;
	        end--;
	}
}

// peek function for stack
Element* peek(Stack* s){
	if (s->top==-1) return NULL;
	return s->elements[s->top];
}

// search for element from top of stack
int search(Stack* s, int k, char* v){
	if (isEmpty(s)) return -1;
	for (int i=0;i<s->capacity;i++){
		if(s->elements[i]->value == v && s->elements[i]->key ==k)return i+1;
	}
	return -1;
}

// get current capacity of stack
int getCapacity(Stack* s){
	return s->capacity;
}

//check if stack is full
bool isFull(Stack* s){
	if (s->top == s->capacity){
		return true;
	}
	return false;
}

// clear the stack
void clear(Stack *s) {
	float temp = s->shrinkFactor;
	s->shrinkFactor=0;
	for(int i = 0; i < s->capacity; i++) {
		pop(s);
	    //free(s->elements[i]);
	}
	s->shrinkFactor=temp;
}

// clean the stack
void cleanStack(Stack *s) {
  for(int i = 0; i < s->capacity; i++) {
    free(s->elements[i]);
  }
	free(s->elements);
	free(s);
}

// current size of stack
int currentSize(Stack* s){
	return s->top;
}

// check if stack empty
bool isEmpty(Stack* s){
	if (s->top==-1){
		return true;
	}
	return false;
}

// Stack with fixed capacity
Stack* makeStack(int cap){
	struct Stack* temp = (struct Stack*) malloc(sizeof(Stack));
	temp->top = -1;
	temp->capacity = cap;
	temp->elements = (struct Element**) malloc(cap*sizeof(Element));
	temp->dynamic = true;
	return temp;
}

// Stack that can grow
Stack* makeStackG(int cap, float growF){
	struct Stack* temp = (struct Stack*) malloc(sizeof(Stack));
	temp->top = -1;
	temp->capacity = cap;
	temp->elements = (struct Element**) malloc(cap*sizeof(Element));
	temp->growthFactor = growF;
	temp->dynamic = true;
	return temp;
}

// Stack that can grow and shrink
Stack* makeStackGnS(int cap, float growF, float shrinkF){
	struct Stack* temp = (struct Stack*) malloc(sizeof(Stack));
	temp->top=-1;
	temp->capacity = cap;
	temp->elements = (struct Element**) malloc(cap*sizeof(Element));
	temp->growthFactor = growF;
	temp->shrinkFactor = shrinkF;
	temp->dynamic = true;
	return temp;
}
