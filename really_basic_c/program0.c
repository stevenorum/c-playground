/*
https://stackoverflow.com/questions/14296235/how-do-i-write-a-character-to-standard-output-in-c-without-using-stdio-h-or-any
This is pretty useless, but for starting from the bare minimum, it's how to print hello world.

compile with: gcc program0.c -o program0
execute with: ./program0
cleanup with: rm program0

*/

int main () {
    char str[] = "Hello, world!\n";
    /* Possible warnings will be encountered here, about implicit declaration of `write` and `strlen` */
    /* strlen(str) can be replaced by 14 if you want to avoid that warning. */
    write(1, str, strlen(str));
    return 0;
}
