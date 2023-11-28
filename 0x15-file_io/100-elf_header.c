#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_magic(unsigned char *e_ident) {
    int i;
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

void print_class(unsigned char e_ident) {
    printf("  Class:                             ");
    switch (e_ident) {
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("Invalid class\n"); break;
    }
}

void print_data(unsigned char e_ident) {
    printf("  Data:                              ");
    switch (e_ident) {
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("Invalid data encoding\n"); break;
    }
}

void print_version(unsigned char e_ident) {
    printf("  Version:                           %u (current)\n", e_ident);
}

void print_osabi(unsigned char e_ident) {
    printf("  OS/ABI:                            ");
    /* Add more cases as necessary */
    switch (e_ident) {
        case ELFOSABI_SYSV:       printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX:       printf("UNIX - HP-UX\n"); break;
        default:                  printf("<unknown: %x>\n", e_ident); break;
    }
}

void print_abi_version(unsigned char e_ident) {
    printf("  ABI Version:                       %u\n", e_ident);
}

void print_type(uint16_t e_type) {
    printf("  Type:                              ");
    switch (e_type) {
        case ET_REL:  printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN:  printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default:      printf("Unknown (%x)\n", e_type); break;
    }
}

void print_entry(uint64_t e_entry) {
    printf("  Entry point address:               0x%lx\n", e_entry);
}

int main(int argc, char *argv[]) {
    int fd;
    Elf64_Ehdr header;

    if (argc != 2) {
        fprintf(stderr, "Usage: elf_header elf_filename\n");
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error: Can't read ELF header of %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident[EI_CLASS]);
    print_data(header.e_ident[EI_DATA]);
    print_version(header.e_ident[EI_VERSION]);
    print_osabi(header.e_ident[EI_OSABI]);
    print_abi_version(header.e_ident[EI_ABIVERSION]);
    print_type(header.e_type);
    print_entry(header.e_entry);

    close(fd);
    return 0;
}

