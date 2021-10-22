#ifndef NEUROMAG2MNE_NEUROMAGSHMEMINFO_HPP
#define NEUROMAG2MNE_NEUROMAGSHMEMINFO_HPP

#define SERVER_PATH         "/neuro/dacq/sockets/dacq_server"
#define CLIENT_PATH         "/neuro/dacq/sockets/dacq_client_"
#define CLIENT_ID           13579   /*Unique id for this app*/

#define SHMEM_MAX_DATA      500*1500*4
#define SHMEM_NUM_BLOCKS    100
#define SHMEM_NO_BUF        -1

namespace sharedMemory{

struct Client{
    int client_id;
    int done;
};

struct Block{
    Client clients[SHMEM_NUM_BLOCKS];
    unsigned char data[SHMEM_MAX_DATA];
};

struct Message{
    int kind;
    int type;
    int size;
    int loc;
    int shmem_buf;
    int shmem_loc;
};
}//namespace
#endif
