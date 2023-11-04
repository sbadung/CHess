#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*  Chessboard:
    00000000
    00000000
    00000000
    00000000
    00000000
    00000000
    00000000
    00000000
*/

/*  0x1FF = 511: https://en.wikipedia.org/wiki/Hexadecimal
    F * 1 = 15
    F * 16 = 240
    1 * 16^2 = 256
    Si poteva scrivere anche come (2 << 9) - 1

    0x1FF << 55
    Righe dei bit: indice del byte
    0
    8
    16
    24
    32
    40
    48
    56
    L'operazione di bitwise shift permette di "spostare" i bit di n posizioni: https://en.wikipedia.org/wiki/Logical_shift
*/

uint64_t whiteKing;
uint64_t whiteQueen;
uint64_t whitePawns = ((uint64_t)0x1F) << 15;
uint64_t whiteRook;
uint64_t whiteBishop;
uint64_t whiteKnight;
uint64_t whiteRook;

uint64_t blackKing;
uint64_t blackQueen;
uint64_t blackPawns = ((uint64_t)0x1F) << 55;
uint64_t blackRook;
uint64_t blackBishop;
uint64_t blackKnight;
uint64_t blackRook;

uint8_t canCastleWhite;
uint8_t canCasteBlack;
uint8_t enPassantSquare;

void printPieceBoard(uint64_t pieceBoard, char pieceChar)
{
    /* https://it.wikipedia.org/wiki/Ordine_dei_byte */
    for (uint8_t i = 0; i < 8; ++i)
    {
        for (uint8_t j = 0, bit = (63 - i * 8 - j); j < 8; ++j)
            printf("%c", (pieceBoard >> bit & 1) ? pieceChar : '0');
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    printPieceBoard(whitePawns, 'P');
    printf("\n");
    printPieceBoard(whiteKing, 'K');
    printf("\n");
    printPieceBoard(blackPawns, 'P');
    return 0;
}
