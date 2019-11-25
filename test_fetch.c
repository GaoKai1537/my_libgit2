#include<git2.h>
#include<zlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<openssl/sha.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    git_libgit2_init();

    git_repository *repo = NULL;
    git_remote *remote;
    git_fetch_options fetch_opts = GIT_FETCH_OPTIONS_INIT;
    int error = 0;

    char *url = argv[1];
    char *path = argv[2];
    char *file_name = argv[3];
    char *name = argv[4];


    if((error = git_repository_open(&repo, path)) < 0) {
        fprintf(stderr, "initialize repository error: %s\n", giterr_last()->message);
        goto cleanup;
    }

    if  ((error = git_remote_lookup(&remote, repo, "origin")) < 0) {
        if((error = git_remote_create(&remote, repo, "origin", url)) < 0) {
            fprintf(stderr, "add remote error: %s\n", giterr_last()->message);
        }
    }
    printf("%s\n", packfile_name);
    packfile_name = name;
    
    error = git_remote_fetch(remote, NULL, &fetch_opts, NULL);
    if(error < 0) {
        fprintf(stderr, "fetch error: %s\n", giterr_last()->message);
        goto cleanup;
    }    
cleanup:
    if (repo) {
        git_repository_free(repo);
    }
    if (remote) {
        git_remote_free(remote);
    }

    git_libgit2_shutdown();
    return 0;
}