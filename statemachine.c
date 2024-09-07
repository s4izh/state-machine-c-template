#include <stdio.h>

typedef enum {
    A,
    B,
    C,
    D,
} state_e;

typedef enum {
    E1,
    E2,
    E3,
    E4,
} event_e;

typedef struct {
    state_e state;

    // more internal state

} state_machine_t;

const char* state_machine_state_to_str(state_e s)
{
    switch (s) {
        case A: return "A";
        case B: return "B";
        case C: return "C";
        case D: return "D";
    }
}

const char* state_machine_event_to_str(event_e ev)
{
    switch (ev) {
        case E1: return "E1";
        case E2: return "E2";
        case E3: return "E3";
        case E4: return "E4";
    }
}

void state_machine_init(state_machine_t* sm)
{
    // initialize all internal state

    sm->state = A;
}

void state_machine_deinit(state_machine_t* sm)
{
    // ensure proper cleanup of internal resources
}

event_e state_machine_wait_for_event()
{
    // logic for waiting
    return E1;
}

void state_machine_set_next_state(state_machine_t* sm, state_e s)
{
    // do something common when setting some state
    // or for example notifiyng state change to external program

    sm->state = s;
}

void state_machine_process_event_from_a(state_machine_t* sm, event_e ev)
{
    switch (ev) {
        case E1:
        {
            // do_something();
            printf("I'm doing something\n");
            state_machine_set_next_state(sm, B);
        }
        break;
        case E2:
        break;
        case E3:
        break;
        case E4:
        break;
    }
}

void state_machine_process_event_from_b(state_machine_t* sm, event_e ev) { return; }
void state_machine_process_event_from_c(state_machine_t* sm, event_e ev) { return; }
void state_machine_process_event_from_d(state_machine_t* sm, event_e ev) { return; }

void state_machine_process_event(state_machine_t* sm, event_e ev)
{
    state_e prev = sm->state;

    switch (sm->state) {
        case A:
            state_machine_process_event_from_a(sm, ev);
            break;
        case B:
            state_machine_process_event_from_b(sm, ev);
            break;
        case C:
            state_machine_process_event_from_c(sm, ev);
            break;
        case D:
            state_machine_process_event_from_d(sm, ev);
            break;
    }

    const char* prev_str = state_machine_state_to_str(prev);
    const char* ev_str = state_machine_event_to_str(ev);
    const char* curr_str = state_machine_state_to_str(sm->state);

    printf("%s -> (%s) -> %s\n", prev_str, ev_str, curr_str);
}

int main(int argc, char *argv[])
{
    state_machine_t sm;
    state_machine_init(&sm);

    while (1) {
        event_e ev = state_machine_wait_for_event();
        state_machine_process_event(&sm, ev);
    }

    state_machine_deinit(&sm);
}
