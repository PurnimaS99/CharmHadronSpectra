// This program is for defining getting V0M for ten percent and min bias

const int n = 10000;

int ntrack = 0, PID[n] = {0}, charge[n] = {0}, V0MMult = 0, a, integral;
double px[n] = {0}, py[n] = {0}, pz[n] = {0}, pT = 0, mass[n] = {0};
double eta[n] = {0}, rap[n] = {0}, phi[n] = {0}, energy[n] = {0};

void centralityndminbias()
{
    gStyle->SetPalette(kRainBow);
    TFile *f = TFile::Open("/home/puri/pythia8308/examples/practice/finalpp/finalpp.root");

    TCanvas *c = new TCanvas("c", "c", 750, 600);
    TH1D *h3 = new TH1D("centrality", "This is the centralitysp distribution", 201, -0.5, 200.5);
   
     TH1D *h4 = new TH1D("V0sp", "This is the V0sp distribution", 201, -0.5, 200.5);
    TTree *theTree = (TTree *)f->Get("t");

    theTree->SetBranchAddress("ntrack", &ntrack); // ntrack is the size of the tree (fill only final chargedparticles)
    theTree->SetBranchAddress("V0MMult", &V0MMult);
    theTree->SetBranchAddress("PID", PID);
    theTree->SetBranchAddress("charge", charge);
    theTree->SetBranchAddress("px", px);
    theTree->SetBranchAddress("py", py);
    theTree->SetBranchAddress("pz", pz);
    theTree->SetBranchAddress("energy", energy);

     int nevents = 100000;
    for (int i = 0; i < nevents; i++)
    {
        theTree->GetEntry(i);
        if (V0MMult<16) continue;
        h3->Fill(V0MMult);
    }

    for (int i = 0; i < nevents; i++)
    {
        theTree->GetEntry(i);
        h4->Fill(V0MMult);
    }

    TFile *f2 = new TFile("multiplicityratio_plot.root", "recreate");

    h3->Write("centrality");
    h4->Write("Minbias");

    f2->Close();

}

