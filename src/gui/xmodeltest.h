#ifndef XMODELTEST_H
#define XMODELTEST_H

#include "gui/qdebugstream.h"
#include "gui/mydebugstream.h"
#include "../modeltest.h"

#include <QMainWindow>
#include <QtGui/QListWidgetItem>

enum msg_level_id {
    msg_lvl_error,
    msg_lvl_alert,
    msg_lvl_notify,
    msg_lvl_info
};

#define st_active       (1<<0)
#define st_msa_loaded   (1<<1)
#define st_tree_loaded  (1<<2)
#define st_parts_loaded (1<<3)
#define st_optimizing   (1<<4)
#define st_optimized    (1<<5)

namespace Ui {
class xmodeltest;
}

class xmodeltest : public QMainWindow
{
    Q_OBJECT

public:
    explicit xmodeltest(QWidget *parent = 0);
    ~xmodeltest();

public slots:
    void setText( QString message );
    void optimization_done(partition_id_t part_id );
    //void print_to_console(const char *message);

private slots:
    void on_act_open_msa_triggered();
    void on_mnu_open_msa_triggered();
    void on_tool_open_msa_clicked();

    void on_act_open_tree_triggered();
    void on_mnu_open_tree_triggered();
    void on_tool_open_tree_clicked();

    void on_act_toggle_settings_triggered();
    void on_mnu_toggle_settings_triggered(bool checked);
    void on_tool_settings_toggled(bool checked);

    void on_act_run_triggered();
    void on_mnu_run_triggered();
    void on_tool_run_clicked();
    void run_modelselection();

    void on_act_reset_triggered();
    void on_mnu_reset_triggered();
    void on_tool_reset_clicked();

    /** SETTINGS **/
    void autoSelectSchemes(const int schemes[], int n);
    void on_radSchemes3_clicked();
    void on_radSchemes5_clicked();
    void on_radSchemes7_clicked();
    void on_radSchemes11_clicked();
    void on_radSchemes203_clicked();

    void on_radSetModelTest_clicked();
    void on_radSetMrbayes_clicked();
    void on_radSetRaxml_clicked();
    void on_radSetPhyml_clicked();
    void on_radSetModelTest_toggled(bool checked);
    void on_radSetMrbayes_toggled(bool checked);
    void on_radSetRaxml_toggled(bool checked);
    void on_radSetPhyml_toggled(bool checked);

    void on_cbEqualFreq_toggled(bool checked);
    void on_cbMlFreq_toggled(bool checked);
    void on_cbNoRateVarModels_toggled(bool checked);
    void on_cbIModels_toggled(bool checked);
    void on_cbGModels_toggled(bool checked);
    void on_cbIGModels_toggled(bool checked);
    void on_cbAdvanced_clicked();
    void on_sliderNThreads_valueChanged(int value);
    void on_radDatatypeDna_clicked();
    void on_radDatatypeProt_clicked();
    void on_cbShowMatrices_clicked();
    void on_radSchemesUser_clicked();
    void on_modelsListView_itemClicked(QListWidgetItem *item);

    void on_sliderNCat_valueChanged(int value);
    void on_sliderNCat_sliderMoved(int position);

private:
    void toggle_settings( bool value );
    void action_open_msa( void );
    void action_open_tree( void );
    void action_run( void );
    void action_reset( void );
    void update_gui( void );
    void reset_xmt( void );

    size_t compute_size(int n_cats, int n_threads);

    Ui::xmodeltest *ui;
    std::string msa_filename;
    std::string utree_filename;
    std::string parts_filename;

    mt_size_t n_seqs;
    mt_size_t seq_len;
    unsigned long status;

    //Q_DebugStream *redirect;
    MyDebugStream *redirect;

    modeltest::ModelTest *mtest;
    std::vector<modeltest::Model *> c_models;
    partitioning_scheme_t * scheme;
    tree_type start_tree;
    mt_options opts;
};

#endif // XMODELTEST_H
