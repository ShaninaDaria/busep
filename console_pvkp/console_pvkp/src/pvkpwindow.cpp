#include "../hdr/pvkpwindow.h"
#include "ui_pvkpwindow.h"

PVKPWindow::PVKPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVKPWindow)
{
    ui->setupUi(this);

    green_palette.setColor(ui->pushButton->backgroundRole(), QColor(0, 255, 0) );
    red_palette.setColor(ui->pushButton->backgroundRole(), QColor(255, 0, 0) );
//    red_palette.setColor(QPalette::ColorRole::Background, QColor(255, 0, 0) );    // рамка
    fictitiousOutputColor();
    fictitiousInputColor();
}

PVKPWindow::~PVKPWindow()
{
    delete ui;
}

void PVKPWindow::fictitiousOutputColor()
{
    ui->pushButton->setPalette(green_palette);
    ui->pushButton_2->setPalette(red_palette);
    ui->pushButton_3->setPalette(green_palette);
    ui->pushButton_4->setPalette(green_palette);
    ui->pushButton_5->setPalette(green_palette);
    ui->pushButton_6->setPalette(green_palette);
    ui->pushButton_7->setPalette(green_palette);
    ui->pushButton_8->setPalette(red_palette);
    ui->pushButton_9->setPalette(green_palette);
    ui->pushButton_10->setPalette(green_palette);
    ui->pushButton_11->setPalette(green_palette);
    ui->pushButton_12->setPalette(green_palette);
    ui->pushButton_13->setPalette(green_palette);
    ui->pushButton_14->setPalette(green_palette);
    ui->pushButton_15->setPalette(green_palette);
    ui->pushButton_16->setPalette(green_palette);
    ui->pushButton_17->setPalette(red_palette);
    ui->pushButton_18->setPalette(green_palette);
    ui->pushButton_19->setPalette(green_palette);
    ui->pushButton_20->setPalette(green_palette);
    ui->pushButton_21->setPalette(green_palette);
    ui->pushButton_22->setPalette(green_palette);
    ui->pushButton_23->setPalette(green_palette);
    ui->pushButton_24->setPalette(green_palette);
    ui->pushButton_25->setPalette(green_palette);
    ui->pushButton_26->setPalette(green_palette);
    ui->pushButton_27->setPalette(green_palette);
    ui->pushButton_28->setPalette(green_palette);
    ui->pushButton_29->setPalette(green_palette);
    ui->pushButton_30->setPalette(green_palette);
    ui->pushButton_31->setPalette(green_palette);
    ui->pushButton_32->setPalette(red_palette);
    ui->pushButton_33->setPalette(green_palette);
    ui->pushButton_34->setPalette(green_palette);
    ui->pushButton_35->setPalette(green_palette);
    ui->pushButton_36->setPalette(green_palette);
    ui->pushButton_37->setPalette(green_palette);
    ui->pushButton_38->setPalette(green_palette);
    ui->pushButton_39->setPalette(green_palette);
    ui->pushButton_40->setPalette(green_palette);
    ui->pushButton_41->setPalette(green_palette);
    ui->pushButton_42->setPalette(red_palette);
    ui->pushButton_43->setPalette(green_palette);
    ui->pushButton_44->setPalette(green_palette);
    ui->pushButton_45->setPalette(green_palette);
    ui->pushButton_46->setPalette(green_palette);
    ui->pushButton_47->setPalette(green_palette);
    ui->pushButton_48->setPalette(green_palette);
    ui->pushButton_49->setPalette(green_palette);
    ui->pushButton_50->setPalette(green_palette);
    ui->pushButton_51->setPalette(red_palette);
    ui->pushButton_52->setPalette(green_palette);
    ui->pushButton_53->setPalette(green_palette);
    ui->pushButton_54->setPalette(green_palette);
    ui->pushButton_55->setPalette(green_palette);
    ui->pushButton_56->setPalette(green_palette);
    ui->pushButton_57->setPalette(green_palette);
    ui->pushButton_58->setPalette(green_palette);
    ui->pushButton_59->setPalette(green_palette);
    ui->pushButton_60->setPalette(green_palette);
    ui->pushButton_61->setPalette(red_palette);
    ui->pushButton_62->setPalette(green_palette);
}

void PVKPWindow::fictitiousInputColor()
{
    ui->pushButton_63->setPalette(green_palette);
    ui->pushButton_63 ->setPalette(green_palette);
    ui->pushButton_64 ->setPalette(green_palette);
    ui->pushButton_65 ->setPalette(green_palette);
    ui->pushButton_66 ->setPalette(green_palette);
    ui->pushButton_67 ->setPalette(green_palette);
    ui->pushButton_68 ->setPalette(green_palette);
    ui->pushButton_69 ->setPalette(green_palette);
    ui->pushButton_70 ->setPalette(red_palette);
    ui->pushButton_71 ->setPalette(green_palette);
    ui->pushButton_72 ->setPalette(green_palette);
    ui->pushButton_73 ->setPalette(green_palette);
    ui->pushButton_74 ->setPalette(green_palette);
    ui->pushButton_75 ->setPalette(green_palette);
    ui->pushButton_76 ->setPalette(green_palette);
    ui->pushButton_77 ->setPalette(green_palette);
    ui->pushButton_78 ->setPalette(green_palette);
    ui->pushButton_79 ->setPalette(green_palette);
    ui->pushButton_80 ->setPalette(green_palette);
    ui->pushButton_81 ->setPalette(green_palette);
    ui->pushButton_82 ->setPalette(green_palette);
    ui->pushButton_83 ->setPalette(green_palette);
    ui->pushButton_84 ->setPalette(red_palette);
    ui->pushButton_85 ->setPalette(green_palette);
    ui->pushButton_86 ->setPalette(green_palette);
    ui->pushButton_87 ->setPalette(green_palette);
    ui->pushButton_88 ->setPalette(green_palette);
    ui->pushButton_89 ->setPalette(green_palette);
    ui->pushButton_90 ->setPalette(green_palette);
    ui->pushButton_91 ->setPalette(green_palette);
    ui->pushButton_92 ->setPalette(green_palette);
    ui->pushButton_93 ->setPalette(green_palette);
    ui->pushButton_94 ->setPalette(green_palette);
    ui->pushButton_95 ->setPalette(green_palette);
    ui->pushButton_96 ->setPalette(red_palette);
    ui->pushButton_97 ->setPalette(green_palette);
    ui->pushButton_98 ->setPalette(green_palette);
    ui->pushButton_99 ->setPalette(green_palette);
    ui->pushButton_100->setPalette(green_palette);
    ui->pushButton_101->setPalette(red_palette);
    ui->pushButton_102->setPalette(green_palette);
    ui->pushButton_103->setPalette(green_palette);
    ui->pushButton_104->setPalette(green_palette);
    ui->pushButton_105->setPalette(green_palette);
    ui->pushButton_106->setPalette(green_palette);
    ui->pushButton_107->setPalette(green_palette);
    ui->pushButton_108->setPalette(green_palette);
    ui->pushButton_109->setPalette(green_palette);
    ui->pushButton_110->setPalette(green_palette);
    ui->pushButton_111->setPalette(green_palette);
    ui->pushButton_112->setPalette(green_palette);
    ui->pushButton_113->setPalette(green_palette);
    ui->pushButton_114->setPalette(red_palette);
    ui->pushButton_115->setPalette(green_palette);
    ui->pushButton_116->setPalette(green_palette);
    ui->pushButton_117->setPalette(green_palette);
    ui->pushButton_118->setPalette(green_palette);
    ui->pushButton_119->setPalette(green_palette);
    ui->pushButton_120->setPalette(green_palette);
    ui->pushButton_121->setPalette(green_palette);
    ui->pushButton_122->setPalette(green_palette);
    ui->pushButton_123->setPalette(green_palette);
    ui->pushButton_124->setPalette(green_palette);
    ui->pushButton_125->setPalette(green_palette);
    ui->pushButton_126->setPalette(green_palette);
    ui->pushButton_127->setPalette(green_palette);
    ui->pushButton_128->setPalette(green_palette);
    ui->pushButton_129->setPalette(red_palette);
    ui->pushButton_130->setPalette(green_palette);
    ui->pushButton_131->setPalette(green_palette);
    ui->pushButton_132->setPalette(green_palette);
    ui->pushButton_133->setPalette(green_palette);
    ui->pushButton_134->setPalette(green_palette);
    ui->pushButton_135->setPalette(green_palette);
    ui->pushButton_136->setPalette(green_palette);
    ui->pushButton_137->setPalette(green_palette);
    ui->pushButton_138->setPalette(green_palette);
    ui->pushButton_139->setPalette(green_palette);
    ui->pushButton_140->setPalette(red_palette);
    ui->pushButton_141->setPalette(green_palette);
    ui->pushButton_142->setPalette(green_palette);
    ui->pushButton_143->setPalette(red_palette);
    ui->pushButton_144->setPalette(green_palette);
    ui->pushButton_145->setPalette(green_palette);
    ui->pushButton_146->setPalette(green_palette);
    ui->pushButton_147->setPalette(green_palette);
    ui->pushButton_148->setPalette(green_palette);
    ui->pushButton_149->setPalette(green_palette);
    ui->pushButton_150->setPalette(green_palette);
    ui->pushButton_151->setPalette(green_palette);
    ui->pushButton_152->setPalette(green_palette);
    ui->pushButton_153->setPalette(green_palette);
    ui->pushButton_154->setPalette(green_palette);
    ui->pushButton_155->setPalette(red_palette);
    ui->pushButton_156->setPalette(green_palette);
    ui->pushButton_157->setPalette(green_palette);
    ui->pushButton_158->setPalette(green_palette);
    ui->pushButton_159->setPalette(green_palette);
    ui->pushButton_160->setPalette(green_palette);
    ui->pushButton_161->setPalette(red_palette);
    ui->pushButton_162->setPalette(green_palette);
    ui->pushButton_163->setPalette(green_palette);
    ui->pushButton_164->setPalette(green_palette);
    ui->pushButton_165->setPalette(green_palette);
    ui->pushButton_166->setPalette(green_palette);
    ui->pushButton_187->setPalette(green_palette);
    ui->pushButton_274->setPalette(green_palette);
    ui->pushButton_275->setPalette(green_palette);
    ui->pushButton_276->setPalette(green_palette);
    ui->pushButton_277->setPalette(green_palette);
    ui->pushButton_278->setPalette(green_palette);
    ui->pushButton_279->setPalette(green_palette);
    ui->pushButton_280->setPalette(red_palette);
    ui->pushButton_281->setPalette(green_palette);
    ui->pushButton_282->setPalette(green_palette);
    ui->pushButton_283->setPalette(green_palette);
    ui->pushButton_284->setPalette(green_palette);
    ui->pushButton_285->setPalette(green_palette);
    ui->pushButton_286->setPalette(green_palette);
    ui->pushButton_287->setPalette(green_palette);
    ui->pushButton_288->setPalette(green_palette);
    ui->pushButton_289->setPalette(green_palette);
    ui->pushButton_290->setPalette(red_palette);
    ui->pushButton_291->setPalette(green_palette);
    ui->pushButton_312->setPalette(green_palette);
    ui->pushButton_312->setPalette(green_palette);
}
