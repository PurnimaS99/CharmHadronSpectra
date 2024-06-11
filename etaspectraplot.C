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

void etaspectraplot()
{
    gStyle->SetOptStat(0);
    // gStyle->SetPalette(kRainBow);
    TFile *file = new TFile("etaspectra_plot.root");

    TCanvas *c = new TCanvas("c", "c", 750, 600);
    c->SetLogy();
    setpad(c);
    c->Draw();

    TH2* h2 = new TH2D("h2", "", 10,-3.0,3.0,10,1e-06,1e-01);
    h2->GetYaxis()->SetTitle("1/N_{ev} dN/d#eta");
    h2->GetXaxis()->SetTitle("#eta");


    TH1D *h[5];
    // const Char_t partname[9][8] = {"Ds", "Dp", "DZero","lambc", "Jsi"};

    TString partname[5] = {"Ds", "Dp", "DZero","lambc", "Jsi"};
    Int_t color[9] = {kRed, kGreen, kBlue, kOrange, kRed + 2, kGreen + 2, kBlue + 2, kOrange + 2, kPink};
    Int_t markerstyle[9] = {20, 21, 22, 23, 24, 25, 26, 27, 28};
    Int_t markersize[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 5; i++)
    {
        // h[i] = (TH1D *)file->Get(Form("%s", partname[i]));
        h[i] = (TH1D *)file->Get(partname[i]);
        h[i]->SetMarkerColor(color[i]);
        h[i]->SetLineColor(color[i]);
        h[i]->SetMarkerStyle(markerstyle[i]);
        h[i]->SetMarkerSize(markersize[i]);
    }

 

    h2->Draw();
    h[0]->Draw("pesame");
    h[1]->Draw("pesame");
    h[2]->Draw("pesame");
    h[3]->Draw("pesame");
    h[4]->Draw("pesame");
    
    TLegend *legend = new TLegend(0.55, 0.69, 0.93, 0.92); // the dimension specified within the bracket specifies the position of the following names in canvas

    legend->AddEntry(h[0], "D_{s}", "lp");
    legend->AddEntry(h[1], "D^{#pm}", "lp");
    legend->AddEntry(h[2], "D_{0}", "lp");
    legend->AddEntry(h[3], "#Lambda_{c}", "lp");
    legend->AddEntry(h[4], "J/#psi", "lp");
    legend->SetNColumns(2);
    legend->SetBorderSize(0);
    
    legend->Draw("same");


   TPaveText *pt = new TPaveText(0.18, 0.77, 0.56, 0.92, "brNDC");
   pt->AddText("pp,#sqrt{s} = 13 TeV (PYTHIA)");
   pt->AddText("MPI, CR mode 2");
   pt->AddText("|#eta|<2.0");
//    pt->SetBorderSize(0);
   pt->Draw("same");

   
    c->SaveAs("etaplot.pdf");
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