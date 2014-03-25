module main;

import std.stdio;
import std.file;

int main(string[] args)
{
    auto tape = getTapeFromFile("task20-tape.txt");
    auto instructions = getInstructionsFromFile("task20-instructions.txt");

    writeln("Tape: ", tape);
    //writeln(instructions);

    char[2] Q = "q0";

    CurrentState currentState;
    NextState nextState;

    int pos = 0;            // current position

    while(Q != "qy" && Q != "qn")
    {

        currentState.q = Q[];
        currentState.symbol = tape[pos];

        nextState = findInstruction(currentState, instructions);

        tape[pos] = nextState.symbol;

        if(nextState.move == 'R')
            ++pos;
        else if (nextState.move == 'L')
            --pos;

        Q[] = nextState.q[];
    }

    writeln("Result tape: ", tape);

    writeln("Programm has ended with answer: ", (Q == "qy" ? "yes" : "no") );

    return 0;
}

NextState findInstruction(CurrentState currentState, Instruction instructions[])
{
    for(int i = 0; i <instructions.length; ++i)
    {
        if( currentState == instructions[i].currentState)
            return instructions[i].nextState;
    }

    NextState bad;
    bad.q ~= "qn";
    return bad;
}

Instruction[] getInstructionsFromFile(string filename)
{
    auto file = File(filename, "r");

    Instruction instructions[];

    Instruction temp;
    char[2] q;

    file.readf(" %c", &q[0]);
    file.readf(" %c", &q[1]);
    temp.currentState.q ~= q[0];
    temp.currentState.q ~= q[1];
    file.readf(" %c", &temp.currentState.symbol);

    file.readf(" %c", &q[0]);
    file.readf(" %c", &q[1]);
    temp.nextState.q ~= q[0];
    temp.nextState.q ~= q[1];
    file.readf(" %c", &temp.nextState.symbol);
    file.readf(" %c", &temp.nextState.move);


    while( !file.eof() )
    {
        instructions ~= temp;

        temp.currentState.q.length = 0;
        temp.nextState.q.length = 0;

        file.readf(" %c", &q[0]);
        file.readf(" %c", &q[1]);
        temp.currentState.q ~= q[0];
        temp.currentState.q ~= q[1];
        file.readf(" %c", &temp.currentState.symbol);

        file.readf(" %c", &q[0]);
        file.readf(" %c", &q[1]);
        temp.nextState.q ~= q[0];
        temp.nextState.q ~= q[1];
        file.readf(" %c", &temp.nextState.symbol);
        file.readf(" %c", &temp.nextState.move);
    }

    return instructions;
}

char[] getTapeFromFile(string filename)
{
    auto file = File(filename, "r");

    char[] tape;            //    tape

    char temp;

    file.readf(" %c", &temp);

    while( !file.eof())
    {
        tape ~= temp;
        file.readf(" %c", &temp);
    }

    return tape;
}

struct Instruction
{
    CurrentState currentState;
    NextState nextState;
};

struct CurrentState
{
    char[] q;
    char symbol;
};

struct NextState
{
    char[] q;
    char symbol;
    char move;
};
