void SetStyle(Bool_t graypalette = kTRUE);

void sethisto(TH2F *r1__1)
{
    r1__1->SetStats(0);
    // r1__1->GetXaxis()->SetTitle("p_{T}[GeV/c]");
    // r1__1->GetXaxis()->CenterTitle(true);
    r1__1->GetXaxis()->SetLabelFont(42);
    r1__1->GetXaxis()->SetNdivisions(510);
    r1__1->GetXaxis()->SetLabelOffset(0.01);
    r1__1->GetXaxis()->SetLabelSize(0.05);
    r1__1->GetXaxis()->SetTitleSize(0.05);
    r1__1->GetXaxis()->SetTickLength(0.04);
    r1__1->GetXaxis()->SetTitleOffset(1.2);
    r1__1->GetXaxis()->SetTitleFont(42);

    // r1__1->GetYaxis()->SetTitle("#frac{1}{2#piN_{eV}} #frac{d^{2}N}{dy dp_{T}} [(GeV/c)^{-1}]");
    r1__1->GetYaxis()->SetNdivisions(510);
    r1__1->GetYaxis()->SetLabelFont(42);
    r1__1->GetYaxis()->SetLabelOffset(0.01);
    r1__1->GetYaxis()->SetLabelSize(0.06);
    r1__1->GetYaxis()->SetTitleSize(0.06);
    r1__1->GetYaxis()->SetTickLength(0.02);
    r1__1->GetYaxis()->SetTitleOffset(1.24);
    r1__1->GetYaxis()->SetTitleFont(42);
    r1__1->GetZaxis()->SetLabelFont(42);
    r1__1->GetZaxis()->SetLabelSize(0.06);
    r1__1->GetZaxis()->SetTitleSize(0.06);
    r1__1->GetZaxis()->SetTitleOffset(1);
    r1__1->GetZaxis()->SetTitleFont(42);
    // r1__1->GetYaxis()->SetMoreLogLabels(kTRUE);
    r1__1->Draw("");
}

void setpad(TPad *c_1)
{
    c_1->Draw();
    c_1->cd();
    //   c_1->Range(-0.427002,-0.01611993,4.141898,0.06259125);
    c_1->SetFillColor(0);
    c_1->SetBorderMode(0);
    c_1->SetBorderSize(1);
    c_1->SetTickx(1);
    c_1->SetTicky(1);
    c_1->SetLeftMargin(0.14);
    c_1->SetBottomMargin(0.13);
    c_1->SetTopMargin(0.04);
    c_1->SetRightMargin(0.03);
    c_1->SetFrameBorderMode(0);
    c_1->SetFrameLineWidth(1);
    c_1->SetFrameBorderMode(0);
}

void setlegendstyle(TLegend *leg1)
{
    leg1->SetBorderSize(1);
    leg1->SetLineColor(0);
    leg1->SetLineStyle(1);
    leg1->SetLineWidth(1);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(1001);
}

void plot_spectra()
{
    gStyle->SetOptStat(0);
    // gStyle->SetPalette(kRainBow);
    TFile *file = new TFile("spectra_plot.root");

    TCanvas *c[5];
    TLegend *legend[5];

   TH2* h2 = new TH2D("h2", "", 100, 0,10.0,100,1e-010,1e-03);
    h2->GetYaxis()->SetTitle("1/N_{ev} d^{2}N/(dy dp_{T}) (GeV/#it{c})^{-1}");
    h2->GetXaxis()->SetTitle("p_{T} (GeV/#it{c})");


    TH1D *h[15];
    // const Char_t partname[9][8] = {"Ds", "Dp", "DZero","lambc", "Jsi"};

    TString partname[15] = {"DsM1", "DsM2", "DsM3","DpM1", "DpM2", "DpM3","DZeroM1","DZeroM2", "DZeroM3", "lambcM1", "lambcM2"
    ,"lambcM3", "JsiM1", "JsiM2", "JsiM3"};
    TString partID[5]= {"Ds", "Dp", "DZero", "lambc", "Jsi"};
    TString partID1[5]= {"D_{s}", "D^{#pm}", "D^{0}", "#Lambda_{c}", "J/#psi"};
    Int_t color[3] = {kRed, kGreen, kBlue} ;
    Int_t markerstyle[3] = {20, 21, 22};
    Int_t markersize[3] = {1, 1, 1};

    for(int j = 0; j < 5; j++)
    {
     c[j] = new TCanvas("", "", 750, 600);
     c[j]->SetLogy();
     setpad(c[j]);
     c[j]->Draw();

     h2->Draw();

     for (int i = 0; i < 3; i++)
     {
        // h[i] = (TH1D *)file->Get(Form("%s", partname[i]));
        h[3*j + i] = (TH1D *)file->Get(partname[3*j + i]);
        h[3*j + i]->SetMarkerColor(color[i]);
        h[3*j + i]->SetLineColor(color[i]);
        h[3*j + i]->SetMarkerStyle(markerstyle[i]);
        h[3*j + i]->SetMarkerSize(markersize[ i]);
        h[3*j + i]->Draw("pesame");
     }
    legend[j] = new TLegend(0.55, 0.69, 0.93, 0.92);
    legend[j]->SetHeader("Multiplicity, "+partID1[j],"C");
    legend[j]->AddEntry(h[3*j + 0], "(16-12)", "lp");
    legend[j]->AddEntry(h[3*j + 1], "12-9", "lp");
    legend[j]->AddEntry(h[3*j + 2], "9-6", "lp");
     legend[j]->SetNColumns(2);
    legend[j]->SetBorderSize(0);
    
    legend[j]->Draw("same");
    c[j]->SaveAs(partID[j]+".pdf");
    }
    // h[3]->Draw("pesame");
    // h[4]->Draw("pesame");
    // h[5]->Draw("pesame");
    // h[6]->Draw("pesame");
    
    // TLegend *legend = new TLegend(0.55, 0.69, 0.93, 0.92); // the dimension specified within the bracket specifies the position of the following names in canvas
    // legend->SetHeader("Multiplicity","C");
    // legend->AddEntry(h[0], "(16-12)", "lp");
    // legend->AddEntry(h[1], "12-9", "lp");
    // legend->AddEntry(h[2], "9-6", "lp");
    // legend->AddEntry(h[3], "D_{s3}", "lp");
    // legend->AddEntry(h[4], "D_{s4}", "lp");
    // legend->AddEntry(h[5], "D_{s5}", "lp");
    // legend->AddEntry(h[6], "D_{s6}", "lp");
   


   TPaveText *pt = new TPaveText(0.18, 0.77, 0.56, 0.92, "brNDC");
   pt->AddText("pp,#sqrt{s} = 13 TeV (PYTHIA)");
   pt->AddText("MPI, CR mode 2");
   pt->AddText("|#eta|<2.0");
//    pt->SetBorderSize(0);
   pt->Draw("same");

   
    // c->SaveAs("DpT.pdf");
}

void SetStyle(Bool_t graypalette)
{
    // cout << "Setting style!" << endl;

    gStyle->Reset("Plain");
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);
    if (graypalette)
        gStyle->SetPalette(8, 0);
    else
        gStyle->SetPalette(1);
    gStyle->SetCanvasColor(10);
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetFrameLineWidth(1);
    gStyle->SetFrameFillColor(kWhite);
    gStyle->SetPadColor(10);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetPadTopMargin(0.1);
    gStyle->SetPadRightMargin(0.1);
    gStyle->SetPadBottomMargin(0.35);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetNdivisions(505, "y");
    gStyle->SetNdivisions(510, "x");

    gStyle->SetHistLineWidth(1);
    // gStyle->SetHistLineColor(kRed);
    gStyle->SetFuncWidth(2);
    // gStyle->SetFuncColor(kBlack);
    gStyle->SetLineWidth(2);
    gStyle->SetLabelSize(0.06, "xyz");
    gStyle->SetLabelOffset(0.01, "y");
    gStyle->SetLabelOffset(0.01, "x");
    gStyle->SetLabelColor(kBlack, "xyz");
    gStyle->SetTitleSize(0.06, "xyz");
    gStyle->SetTitleOffset(1.1, "y");
    gStyle->SetTitleOffset(1.1, "x");
    gStyle->SetTitleFillColor(kWhite);
    gStyle->SetTextSizePixels(26);
    gStyle->SetTextFont(42);
    gStyle->SetTickLength(0.04, "X");
    gStyle->SetTickLength(0.02, "Y");
    gStyle->SetLegendBorderSize(0);
    gStyle->SetLegendFillColor(kWhite);
    gStyle->SetLegendFont(42);
}