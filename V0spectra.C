   const int n=1000;

    int ntrack=0,PID[n]={0},charge[n]={0}, V0MMult=0;
    double px[n]={0},py[n]={0},pz[n]={0},pT=0,mass[n]={0};
    double eta[n]={0},rap[n]={0},phi[n]={0}, energy[n]={0};

void V0spectra()
{
    gStyle->SetPalette(kRainBow);
    TFile *f = TFile::Open("/home/puri/pythia8308/examples/practice/finalpp/finalpp.root");

    TCanvas *c = new TCanvas("c","c", 750,600);
    TH1D *V0sp = new TH1D("V0sp","This is the V0sp distribution",50,0,50);
    V0sp->SetLineColor(kRed );
    V0sp->SetMarkerColor(kRed );
    V0sp->SetMarkerSize(1);
    V0sp->SetMarkerStyle(20);
    V0sp->SetTitle("V0M Distribution; V0M/#Delta#eta; P(V0M)");
    // V0sp->GetYaxis()->SetTitle("count");
    // V0sp->GetXaxis()->SetTitle("V0m/4.3");
     c->SetLogy();
    c->Draw();

    TTree *theTree = (TTree*)f->Get("t");
	  
	theTree->SetBranchAddress("ntrack", &ntrack);  //ntrack is the size of the tree (fill only final chargedparticles)  
    theTree->SetBranchAddress("V0MMult", &V0MMult);
	theTree->SetBranchAddress("PID", PID);
	theTree->SetBranchAddress("charge",charge);
	theTree->SetBranchAddress("px",px);
	theTree->SetBranchAddress("py",py);
	theTree->SetBranchAddress("pz",pz);
    theTree->SetBranchAddress("energy",energy);

    // const Int_t nevents = (Int_t)theTree->GetEntries();
    int nevents = 100000;
    for(int i=0;i<nevents; i++)
    {
         theTree->GetEntry(i);
         V0sp->Fill(V0MMult/4.3);

         cout<<V0MMult/4.3<<endl;
    }
    V0sp->Scale(  );
    V0sp->Draw("E1,p");
    c->SaveAs("V0spectra.pdf");

}