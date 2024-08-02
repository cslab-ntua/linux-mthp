#define CREATE_TRACE_POINTS
#include <trace/events/pftrace.h>

void do_trace_fault(unsigned long cycles) {
	trace_fault(cycles);
}

void do_trace_allocpages(unsigned long cycles) {
	trace_allocpages(cycles);
}

void do_trace_rmqueue(unsigned long cycles) {
	trace_rmqueue(cycles);
}

void do_trace_getfreepage(unsigned long cycles) {
	trace_getfreepage(cycles);
}

void do_trace_setpte(unsigned long cycles) {
	trace_setpte(cycles);
}

void do_trace_contpte_flush(unsigned long cycles) {
	trace_contpte_flush(cycles);
}

void do_trace_contpte_set(unsigned long cycles) {
	trace_contpte_set(cycles);
}
