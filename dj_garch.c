//
// Created by kwoodle on 4/9/21.
//
//  gretl -- Gnu Regression, Econometrics and Time-series Library
//  Test gretl garch by calculating garch(1,1) on gretl supplied Down Jones
//  daily close data.

#include <gretl/libgretl.h>

int garch_estimate (DATASET *dset, PRN *prn)
{
    MODEL *model;
    int *list;
    int err;

    model = gretl_model_new();
    list = gretl_list_new(4);

    list[1] = 1;       /* AR order */
    list[2] = 1;       /* MA order */
    list[3] = LISTSEP;   /* separator */
    list[4] = 2;         // Apparently, every dataset has cons in
                         // location 1;

    *model = garch(list, dset, OPT_N, prn);
    err = model->errcode;

    if (err) {
        errmsg(err, prn);
    } else {
        printmodel(model, dset, OPT_NONE, prn);
    }

    gretl_model_free(model);
    free(list);

    return err;
}


int main (void)
{
    DATASET *dset, *dset2;
    PRN *prn;
    int err;

    libgretl_init();

    dset = datainfo_new();
    prn = gretl_print_new(GRETL_PRINT_STDOUT, NULL);

    /* Give the full path to the gretl datafile unless it's
       in the current working directory. Note that PREFIX is
       defined in the Makefile
    */
    err = gretl_read_native_data("/home/kwoodle" "/gretl/pc_djclose.gdt", dset);

    if (err) {
        errmsg(err, prn);
        exit(EXIT_FAILURE);
    }
//    print_sample_obs(dset, prn);
//    print_data_in_columns(NULL, NULL, dset, OPT_NONE, prn);
    err = garch_estimate(dset, prn);

    destroy_dataset(dset);
    gretl_print_destroy(prn);

    libgretl_cleanup();

    return 0;
}
